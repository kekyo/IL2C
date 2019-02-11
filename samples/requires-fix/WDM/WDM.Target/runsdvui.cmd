cd /d "D:\PROJECT\IL2C\tests\WDM\WDM.Target" &msbuild "WDM.Target.vcxproj" /t:sdvViewer /p:configuration="Debug" /p:platform=Win32
exit %errorlevel% 