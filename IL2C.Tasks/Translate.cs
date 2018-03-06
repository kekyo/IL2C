using System;
using Microsoft.Build.Framework;

namespace IL2C.Tasks
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
            var debugInformation = string.IsNullOrWhiteSpace(this.DebugInformation)
                ? DebugInformationOptions.CommentOnly
                : (DebugInformationOptions) Enum.Parse(typeof(DebugInformationOptions), this.DebugInformation);

            foreach (var assemblyPath in this.AssemblyPaths)
            {
                SimpleDriver.Translate(
                    Console.Out,
                    assemblyPath.ItemSpec,
                    this.OutputPath.ItemSpec,
                    this.EnableCpp,
                    debugInformation);
            }

            return true;
        }
    }
}
