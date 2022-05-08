////////////////////////////////////////////////////////////////////////////
//
// IL2C - A translator for ECMA-335 CIL/MSIL to C language.
// Copyright (c) Kouji Matsui (@kozy_kekyo, @kekyo@mastodon.cloud)
//
// Licensed under Apache-v2: https://opensource.org/licenses/Apache-2.0
//
////////////////////////////////////////////////////////////////////////////

#nullable enable

using System;
using System.ComponentModel;
using System.IO;
using System.Threading.Tasks;

namespace IL2C
{
    public enum LogLevels
    {
        Debug = 1,
        Trace,
        Information,
        Warning,
        Error,
        Silent = 100,
    }

    public interface ILogger
    {
        ValueTask OutputLogAsync(
            LogLevels logLevel, FormattableString? message, Exception? ex);
    }

    public static class LoggerExtension
    {
        public static void Debug(this ILogger logger, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Debug, message, null);

        public static void Trace(this ILogger logger, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Trace, message, null);

        public static void Information(this ILogger logger, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Information, message, null);

        public static void Warning(this ILogger logger, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Warning, message, null);
        public static void Warning(this ILogger logger, Exception ex) =>
            _ = logger.OutputLogAsync(LogLevels.Warning, null, ex);
        public static void Warning(this ILogger logger, Exception ex, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Warning, message, ex);

        public static void Error(this ILogger logger, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Error, message, null);
        public static void Error(this ILogger logger, Exception ex) =>
            _ = logger.OutputLogAsync(LogLevels.Error, null, ex);
        public static void Error(this ILogger logger, Exception ex, FormattableString message) =>
            _ = logger.OutputLogAsync(LogLevels.Error, message, ex);

        ////////////////////////////////////////////////

        public static ValueTask DebugAsync(this ILogger logger, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Debug, message, null);

        public static ValueTask TraceAsync(this ILogger logger, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Trace, message, null);

        public static ValueTask InformationAsync(this ILogger logger, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Information, message, null);

        public static ValueTask WarningAsync(this ILogger logger, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Warning, message, null);
        public static ValueTask WarningAsync(this ILogger logger, Exception ex) =>
            logger.OutputLogAsync(LogLevels.Warning, null, ex);
        public static ValueTask WarningAsync(this ILogger logger, Exception ex, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Warning, message, ex);

        public static ValueTask ErrorAsync(this ILogger logger, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Error, message, null);
        public static ValueTask ErrorAsync(this ILogger logger, Exception ex) =>
            logger.OutputLogAsync(LogLevels.Error, null, ex);
        public static ValueTask ErrorAsync(this ILogger logger, Exception ex, FormattableString message) =>
            logger.OutputLogAsync(LogLevels.Error, message, ex);
    }

    public abstract class LoggerBase : ILogger
    {
        public readonly LogLevels BaseLevel;

        protected LoggerBase(LogLevels baseLevel) =>
            this.BaseLevel = baseLevel;

        public async ValueTask OutputLogAsync(
            LogLevels logLevel, FormattableString? message, Exception? ex)
        {
            if (logLevel >= this.BaseLevel)
            {
                await this.OnOutputLogAsync(logLevel, message, ex).
                    ConfigureAwait(false);
            }
        }

        protected virtual string? ToString(
            string? header, LogLevels logLevel, FormattableString? message, Exception? ex)
        {
            static string GetHeaderString(string? header) =>
                header is { } ? $",{header}" : "";
            static string GetLogLevelString(LogLevels logLevel) =>
                logLevel != LogLevels.Information ? $" {logLevel}:" : "";

            switch (message, ex)
            {
                case ({ }, { }):
                    return $"IL2C [{ThisAssembly.AssemblyVersion}]{GetHeaderString(header)}:{GetLogLevelString(logLevel)} {message}, {ex}";
                case ({ }, null):
                    return $"IL2C [{ThisAssembly.AssemblyVersion}]{GetHeaderString(header)}:{GetLogLevelString(logLevel)} {message}";
                case (null, { }):
                    return $"IL2C [{ThisAssembly.AssemblyVersion}]{GetHeaderString(header)}:{GetLogLevelString(logLevel)} {ex}";
                default:
                    return null;
            }
        }

        protected abstract ValueTask OnOutputLogAsync(
            LogLevels logLevel, FormattableString? message, Exception? ex);
    }

    public sealed class TextWriterLogger : LoggerBase, IDisposable
    {
        public readonly TextWriter Writer;

        private readonly string? header;

        public TextWriterLogger(LogLevels baseLevel, TextWriter tw, string? header = null) :
            base(baseLevel)
        {
            this.Writer = tw;
            this.header = header;
        }

        public void Dispose() =>
            this.Writer.Flush();

        protected override async ValueTask OnOutputLogAsync(
            LogLevels logLevel, FormattableString? message, Exception? ex)
        {
            if (base.ToString(this.header, logLevel, message, ex) is { } formatted)
            {
                await this.Writer.WriteLineAsync(formatted).
                    ConfigureAwait(false);
            }
        }
    }
}
