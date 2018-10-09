using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace IL2C
{
    [AttributeUsage(AttributeTargets.Field)]
    internal sealed class OptionAttribute : DescriptionAttribute
    {
        public OptionAttribute(string description) : base(description) { }
        public OptionAttribute(string description, char shortName) : base(description)
        {
            this.ShortName = shortName;
        }

        public char ShortName { get; }
    }

    internal sealed class CommandLineArgumentException : ArgumentException
    {
        public CommandLineArgumentException(string message, string name) : base(message, name)
        {
            this.Message = string.Format("{0}: {1}", message, base.ParamName);
        }

        public CommandLineArgumentException(string message, string parameter, Exception ex) : base(message, parameter, ex)
        {
            this.Message = string.Format("{0}: {1}", message, base.ParamName);
        }

        public override string Message { get; }
    }

    internal sealed class CommandLineExtractor<T>
        where T : new()
    {
        private struct Field
        {
            private readonly FieldInfo field;

            public Field(FieldInfo field)
            {
                this.field = field;
            }

            public string Name =>
                ToKebabCase(field.Name);
            public char ShortName =>
                ((OptionAttribute)field.GetCustomAttribute(typeof(OptionAttribute), true))?.ShortName ?? '\0';
            public string Description =>
                ((DescriptionAttribute)field.GetCustomAttribute(typeof(DescriptionAttribute), true))?.Description ?? string.Empty;

            public int Ordinal => 0;   // TODO:

            public string Usage =>
                this.IsRequired ?
                    this.RawUsage :
                    string.Format("[{0}]", this.RawUsage);

            public string RawUsage =>
                this.IsOption ?
                    (field.FieldType == typeof(bool) ?
                        string.Format("--{0}", this.Name) :
                        string.Format("--{0}=<value>", this.Name)) :
                    string.Format("<{0}>", this.Name);

            public string ArgumentUsage =>
                string.Format("<{0}>", this.Name);

            public bool IsOption =>
                field.IsDefined(typeof(OptionAttribute), true);

            private bool IsNullableValueType =>
                field.FieldType.IsGenericType && (field.FieldType.GetGenericTypeDefinition() == typeof(Nullable<>));

            private bool IsNullable =>
                !field.FieldType.IsValueType || this.IsNullableValueType;

            private bool IsBool =>
                field.FieldType == typeof(bool);

            public bool IsRequired =>
                field.IsDefined(typeof(RequiredAttribute), true) ||
                (!field.IsDefined(typeof(DefaultValueAttribute), true) && !this.IsNullable && !(this.IsOption && this.IsBool));

            private object ConvertTo(object value) =>
                this.IsNullableValueType ?
                    Convert.ChangeType(value, field.FieldType.GenericTypeArguments[0]) :
                    Convert.ChangeType(value, field.FieldType);

            public void SetValue(ref T instance, object value) =>
                field.SetValueDirect(__makeref(instance), ConvertTo(value));
            public void SetDefaultValue(ref T instance)
            {
                var attribute = ((DefaultValueAttribute)field.GetCustomAttribute(typeof(DefaultValueAttribute), false));
                if (attribute != null)
                {
                    this.SetValue(ref instance, attribute.Value);
                }
            }

            private static string ToKebabCase(string str)
            {
                var sb = new StringBuilder();
                foreach (var ch in str)
                {
                    if (char.IsUpper(ch))
                    {
                        if (sb.Length >= 1)
                        {
                            sb.Append('-');
                        }
                        sb.Append(char.ToLower(ch));
                    }
                    else
                    {
                        sb.Append(ch);
                    }
                }
                return sb.ToString();
            }

            public override string ToString() =>
                string.Format("{0}: {1}", this.Name, field.FieldType.Name);
        }

        private readonly Field[] arguments;
        private readonly Dictionary<string, Field> options;
        private readonly Dictionary<string, Field> shortOptions;

        public CommandLineExtractor()
        {
            var fields =
                typeof(T).GetFields().
                Where(field => field.IsPublic && !field.IsStatic && !field.IsLiteral).
                Select(field => new Field(field)).
                ToArray();

            arguments = fields.
                Where(field => !field.IsOption).
                OrderBy(field => field.IsRequired ? 0 : 1).
                ThenBy(field => field.Ordinal).
                ToArray();
            options = fields.
                Where(field => field.IsOption).
                ToDictionary(field => field.Name);
            shortOptions = fields.
                Where(field => field.IsOption && (field.ShortName != '\0')).
                ToDictionary(field => field.ShortName.ToString());
        }

        private static string FoldNonRequiredArgumentUsage(Field[] fields, int index)
        {
            switch (fields.Length - index)
            {
                case 0:
                    return string.Empty;
                case 1:
                    Debug.Assert(!fields[index].IsRequired);
                    return string.Format("[{0}]", fields[index].ArgumentUsage);
                default:
                    Debug.Assert(!fields[index].IsRequired);
                    return string.Format("[{0} {1}]", fields[index].ArgumentUsage, FoldNonRequiredArgumentUsage(fields, index + 1));
            }
        }

        public void WriteUsages(TextWriter tw, string executableName)
        {
            tw.WriteLine(
                "usage: {0} {1}",
                executableName,
                string.Join(
                    " ",
                    options.Values.
                        OrderBy(field => field.Name).
                        Concat(arguments.Where(field => field.IsRequired)).
                        Select(field => field.Usage).
                        Concat(new[] {
                            FoldNonRequiredArgumentUsage(arguments.Where(field => !field.IsRequired).ToArray(), 0) })));

            if (options.Count >= 1)
            {
                var maxLength = options.Values.Max(field => field.RawUsage.Length);
                var pad = new string(' ', maxLength);
                foreach (var field in options.Values.OrderBy(field => field.Name))
                {
                    var usage = (field.RawUsage + pad).Substring(0, maxLength);
                    if (field.ShortName != '\0')
                    {
                        tw.WriteLine(" -{0}, {1} {2}", field.ShortName, usage, field.Description);
                    }
                    else
                    {
                        tw.WriteLine("     {0} {1}", usage, field.Description);
                    }
                }
            }
        }

        public void WriteUsages(TextWriter tw) =>
            WriteUsages(tw, Path.GetFileNameWithoutExtension(Assembly.GetEntryAssembly().Location));

        public T Extract(params string[] args) =>
            Extract((IEnumerable<string>)args);

        private static void ApplyOption(ref T instance, string argument, int startIndex, Dictionary<string, Field> options)
        {
            var index = argument.IndexOf('=');
            var name = (index >= 0) ?
                argument.Substring(startIndex, index - startIndex).Trim() :
                argument.Substring(startIndex).Trim();
            object value = (index >= 0) ?
                (object)argument.Substring(index + 1).Trim() :
                true;

            if (options.TryGetValue(name, out var field))
            {
                try
                {
                    field.SetValue(ref instance, value);
                }
                catch (Exception ex)
                {
                    throw new CommandLineArgumentException("Invalid option value", name, ex);
                }
            }
            else
            {
                throw new CommandLineArgumentException("Unknown option name", name);
            }
        }

        public T Extract(IEnumerable<string> args)
        {
            var instance = new T();
            foreach (var field in options.Values.Concat(arguments))
            {
                field.SetDefaultValue(ref instance);
            }

            var fieldIndex = -1;
            foreach (var arg in args)
            {
                var argument = arg.Trim();
                if (fieldIndex == -1)
                {
                    if ((argument == "-") || (argument == "--"))
                    {
                        fieldIndex = 0;
                        continue;
                    }

                    if (argument.StartsWith("--"))
                    {
                        ApplyOption(ref instance, argument, 2, options);
                        continue;
                    }
                    else if (argument.StartsWith("-"))
                    {
                        ApplyOption(ref instance, argument, 1, shortOptions);
                        continue;
                    }

                    fieldIndex = 0;
                }

                arguments[fieldIndex++].SetValue(ref instance, argument);
            }

            return instance;
        }
    }
}
