////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

using System.IO;
using System.Linq;

using IL2C.Metadata;

namespace IL2C.Writers
{
    internal sealed class DebugInformationWriteController
    {
        private readonly DebugInformationOptions mode;

        private ICodeInformation ci;
        private DebugInformation debug;
        private bool canWriteSequencePoint = true;

        public DebugInformationWriteController(IMethodInformation method, DebugInformationOptions mode)
        {
            this.mode = mode;
            this.debug = method.CodeStream.First().Debug.FirstOrDefault();
        }

        public void SetNextCode(ICodeInformation ci)
        {
            this.ci = ci;

            // Update if only available debug information.
            var debug = ci.Debug.FirstOrDefault();
            if (debug != null)
            {
                this.debug = debug;
            }
        }

        public void WriteCodeComment(CodeTextWriter tw)
        {
            switch (mode)
            {
                case DebugInformationOptions.CommentOnly:
                    if (canWriteSequencePoint && (debug != null))
                    {
                        // Write debugging information (opcode and line information)
                        tw.WriteLine(
                            "/* {0,-40} : {1}({2}) */",
                            ci,
                            Path.GetFileName(debug.Path),
                            debug.Line);
                        canWriteSequencePoint = false;
                    }
                    else
                    {
                        // Write debugging information (only opcode information)
                        tw.WriteLine(
                            "/* {0} */",
                            ci);
                    }
                    break;
                case DebugInformationOptions.Full:
                    // (Full debug information write at the WriteInformationBeforeCode.)
                    tw.WriteLine(
                        "/* {0} */",
                        ci);
                    break;
            }
        }

        public void WriteInformationBeforeCode(CodeTextWriter tw)
        {
            if ((mode == DebugInformationOptions.Full) && (debug != null))
            {
                tw.WriteLineIgnoreIndent(
                    "#line {0} \"{1}\"",
                    debug.Line,
                    debug.Path.Replace("\\", "\\\\"));
            }

            canWriteSequencePoint = true;
        }
    }
}
