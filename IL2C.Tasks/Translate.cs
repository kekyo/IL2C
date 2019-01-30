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
