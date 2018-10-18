using System;
using System.IO;
using System.Threading.Tasks;

namespace IL2C
{
    internal static class TestUtilities
    {
        public static object ConvertTo(object value, Type targetType)
        {
            if (value == null)
            {
                return null;
            }
            else if (value.GetType() == targetType)
            {
                return value;
            }
            else if (targetType == typeof(IntPtr))
            {
                if (value is int)
                {
                    return new IntPtr((int)value);
                }
                else if (value is long)
                {
                    return new IntPtr((long)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else if (targetType == typeof(UIntPtr))
            {
                if (value is uint)
                {
                    return new UIntPtr((uint)value);
                }
                else if (value is ulong)
                {
                    return new UIntPtr((ulong)value);
                }
                else
                {
                    throw new InvalidCastException();
                }
            }
            else
            {
                return Convert.ChangeType(value, targetType);
            }
        }

        private static bool IsStrangeProblemException(Exception ex)
        {
            return
                ex.Message.Contains("not a valid application") ||
                ex.Message.Contains("it is being used by another process") ||
                ex.Message.Contains("system cannot find the file specified") ||
                ex.Message.Contains("file or directory is corrupted and unreadable") ||
                ex.Message.Contains("Permission denied") ||
                ex.Message.Contains("ExitCode=-1073741819");
        }

        // HACK: If use offloading Task rarely causes strange problems, it's workaround by retry. ¯\_(ツ)_/¯
        public static async Task<T> RetryIfStrangeProblemAsync<T>(Func<T> func, int count = 16)
        {
            while (true)
            {
                try
                {
                    return func();
                }
                catch (Exception ex)
                {
                    if (!IsStrangeProblemException(ex))
                    {
                        throw;
                    }
                    if (count-- == 0)
                    {
                        throw;
                    }
                }
                await Task.Delay(100);
            }
        }

        // HACK: If use offloading Task rarely causes strange problems, it's workaround by retry. ¯\_(ツ)_/¯
        public static async Task<T> RetryIfStrangeProblemAsync<T>(Func<Task<T>> func, int count = 16)
        {
            while (true)
            {
                try
                {
                    return await func();
                }
                catch (Exception ex)
                {
                    if (!IsStrangeProblemException(ex))
                    {
                        throw;
                    }
                    if (count-- == 0)
                    {
                        throw;
                    }
                }
                await Task.Delay(100);
            }
        }

        public static Task<Stream> CreateStreamAsync(string path)
        {
            return RetryIfStrangeProblemAsync(() =>
                (Stream)new FileStream(path, FileMode.Create, FileAccess.ReadWrite, FileShare.None, 65536, true));
        }

        public static async Task WriteTextFileAsync(string path, string text)
        {
            using (var fs = await CreateStreamAsync(path))
            {
                var tw = new StreamWriter(fs);

                await tw.WriteAsync(text);
                await tw.FlushAsync();

                fs.Close();
            }
        }
    }
}
