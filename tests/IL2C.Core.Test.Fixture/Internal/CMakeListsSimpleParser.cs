/////////////////////////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) 2016-2019 Kouji Matsui (@kozy_kekyo, @kekyo2)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IL2C.Internal
{
    public static class CMakeListsSimpleParser
    {
        private static IEnumerable<Func<string>> SplitArguments(string args, Dictionary<string, Func<string>> definitions)
        {
            var sb = new StringBuilder();
            var sbKey = new StringBuilder();
            var exprs = new List<Func<string>>();
            var state = 0;
            var quote = false;
            var env = false;
            var index = 0;

            while (index < args.Length)
            {
                var ch = args[index];
                switch (state)
                {
                    case 0:
                        if (quote)
                        {
                            if (ch == '"')
                            {
                                if (sb.Length >= 1)
                                {
                                    var fxd = sb.ToString();
                                    sb.Clear();
                                    exprs.Add(() => fxd);
                                }
                                {
                                    var fxd = string.Concat(exprs.Select(expr => expr()));
                                    exprs.Clear();
                                    yield return () => fxd;
                                }
                                index++;
                                quote = false;
                                continue;
                            }
                        }
                        else
                        {
                            if ((ch == ' ') || (ch == '\t'))
                            {
                                if (sb.Length >= 1)
                                {
                                    var fxd = sb.ToString();
                                    sb.Clear();
                                    exprs.Add(() => fxd);
                                }
                                if (exprs.Count >= 1)
                                {
                                    var fxd = exprs.ToArray();
                                    exprs.Clear();
                                    yield return () => string.Join(string.Empty, fxd.Select(fx => fx()));
                                }
                                index++;
                                continue;
                            }
                        }

                        if (ch == '"')
                        {
                            quote = true;
                            index++;
                        }
                        else if (ch == '$')
                        {
                            if (sb.Length >= 1)
                            {
                                var fxd = sb.ToString();
                                sb.Clear();
                                exprs.Add(() => fxd);
                            }
                            state = 1;
                            index++;
                        }
                        else
                        {
                            sb.Append(ch);
                            index++;
                        }
                        break;
                    case 1:
                        if (ch == '{')
                        {
                            env = sbKey.ToString() == "ENV";
                            sbKey.Clear();
                            state = 2;
                            index++;
                        }
                        else
                        {
                            sbKey.Append(ch);
                            index++;
                        }
                        break;
                    case 2:
                        if (ch == '}')
                        {
                            var fxd = sb.ToString();
                            sb.Clear();
                            if (env)
                            {
                                exprs.Add(() => Environment.GetEnvironmentVariable(fxd));
                            }
                            else
                            {
                                exprs.Add(() => definitions.TryGetValue(fxd, out var value) ? value() : string.Empty);
                            }
                            state = 0;
                            index++;
                        }
                        else
                        {
                            sb.Append(ch);
                            index++;
                        }
                        break;
                }
            }

            if (sb.Length >= 1)
            {
                var fxd = sb.ToString();
                sb.Clear();
                exprs.Add(() => fxd);
            }
            if (exprs.Count >= 1)
            {
                var fxd = exprs.ToArray();
                exprs.Clear();
                yield return () => string.Join(string.Empty, fxd.Select(fx => fx()));
            }
        }

        private static void Append(this Dictionary<string, Func<string>> dict, string key, IEnumerable<Func<string>> exprs, string prefix)
        {
            var fxd = string.Join(" ", exprs.Select(e => prefix + e()));
            if (dict.TryGetValue(key, out var expr))
            {
                var fxd0 = prefix + expr();
                dict[key] = () => fxd0 + " " + fxd;
            }
            else
            {
                dict[key] = () => fxd;
            }
        }

        public static async Task<IReadOnlyDictionary<string, string>> ExtractDefinitionsAsync(
            string cmakeListsPath, IReadOnlyDictionary<string, string> predefinedDefinitions)
        {
            using (var fs = new FileStream(
                cmakeListsPath,
                FileMode.Open, FileAccess.Read, FileShare.ReadWrite,
                65536, true))
            {
                var tr = new StreamReader(fs, Encoding.UTF8, true);
                var definitions = predefinedDefinitions.ToDictionary(
                    entry => entry.Key,
                    entry => new Func<string>(() => entry.Value),
                    StringComparer.InvariantCultureIgnoreCase);

                var runBlock = true;
                var runBlocks = new Stack<bool>();

                while (!tr.EndOfStream)
                {
                    var line = await tr.ReadLineAsync().ConfigureAwait(false);
                    if (line == null)
                    {
                        break;
                    }

                    line = line.Trim();
                    if (line.Length == 0)
                    {
                        continue;
                    }

                    var index = line.IndexOf('(');
                    var statement = (index >= 0) ?
                        line.Substring(0, index).Trim() :
                        line;
                    var args = (index >= 0) ?
                        SplitArguments(line.Substring(index + 1, line.IndexOf(')') - index - 1), definitions).ToArray() :
                        Array.Empty<Func<string>>();

                    switch (statement.ToLowerInvariant())
                    {
                        case "set" when args.Length >= 2:
                            if (runBlock)
                            {
                                var key = args[0]();
                                if (definitions.TryGetValue(key, out var lastValue))
                                {
                                    definitions[key] = () =>
                                        lastValue() + " " +
                                        string.Join(" ", args.Skip(1).Select(arg => arg()));
                                }
                                else
                                {
                                    definitions[key] = () =>
                                        string.Join(" ", args.Skip(1).Select(arg => arg()));
                                }
                            }
                            break;
                        case "if" when args.Length == 3:
                            runBlocks.Push(runBlock);
                            if (runBlock)
                            {
                                switch (args[1]().ToLowerInvariant())
                                {
                                    case "strequal":
                                        runBlock = args[0]() == args[2]();
                                        break;
                                }
                            }
                            break;
                        case "else":
                            runBlock = !runBlock;
                            break;
                        case "endif":
                            runBlock = runBlocks.Pop();
                            break;
                        case "add_definitions":
                            definitions.Append("COMPILE_DEFINITIONS", args, string.Empty);
                            break;
                        case "include_directories":
                            definitions.Append("INCDIR", args, "-I");
                            break;
                        case "link_directories":
                            definitions.Append("LIBDIR", args, "-L");
                            break;
                    }
                }

                return definitions.ToDictionary(
                    entry => entry.Key,
                    entry => entry.Value());
            }
        }
    }
}
