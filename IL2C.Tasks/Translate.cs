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
using System.Linq;
using Microsoft.Build.Framework;

namespace IL2C
{
    public sealed class Translate : Microsoft.Build.Utilities.Task
    {
        public Translate()
        {
            this.DebugInformation = "CommentOnly";
        }

        [Required]
        public ITaskItem[] AssemblyPaths
        {
            get; set; 
        }

        [Required]
        public ITaskItem OutputPath
        {
            get; set;
        }

        public bool ReadSymbols
        {
            get; set;
        }

        public bool EnableCpp
        {
            get; set;
        }

        public bool EnableBundler
        {
            get; set;
        }

        public string DebugInformation
        {
            get; set;
        }

        public override bool Execute()
        {
            var outputPath = this.OutputPath.ItemSpec.Trim();
            var debugInformation = string.IsNullOrWhiteSpace(this.DebugInformation)
                ? DebugInformationOptions.CommentOnly
                : (DebugInformationOptions)Enum.Parse(typeof(DebugInformationOptions), this.DebugInformation);

            var logw = new LogWriter(message =>
                this.Log.LogMessage(
                    MessageImportance.High,
                    "{0}", message));

            SimpleDriver.TranslateAll(
                logw,
                outputPath,
                this.ReadSymbols,
                this.EnableCpp,
                this.EnableBundler,
                debugInformation,
                this.AssemblyPaths.
                    Select(path => path.ItemSpec.Trim()).
                    ToArray());

            return true;
        }
    }
}
