using System;
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

        public bool EnableCpp
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
                : (DebugInformationOptions) Enum.Parse(typeof(DebugInformationOptions), this.DebugInformation);

            var tw = new LogWriter(this.Log);

            foreach (var assemblyPath in this.AssemblyPaths)
            {
                SimpleDriver.Translate(
                    tw,
                    assemblyPath.ItemSpec.Trim(),
                    outputPath,
                    this.EnableCpp,
                    debugInformation);
            }

            return true;
        }
    }
}
