@echo off
setlocal enabledelayedexpansion

set TOOLCHAINPATH=%~dp0toolchain\gcc4
set CMAKE_ROOT=%TOOLCHAINPATH%\share\cmake-3.23

if not exist %TOOLCHAINPATH% (
    echo Native toolchain not found.
    echo Execute "init-tools.bat" if build runtime at first time.
    exit /b 1
)

set BuildIdentifier=%1
if "%BuildIdentifier%" == "" (
    set BuildIdentifier=manually
)

rem =========================================

call build-runtime.bat Debug
call build-runtime.bat Release

rem =========================================

echo.
echo ///////////////////////////////////////////////
echo // Build entire IL2C.pack.sln
echo.

dotnet build --configuration Release -p:Platform="Any CPU" -p:BuildIdentifier="%BuildIdentifier%" il2c.pack.sln

rem =========================================

echo.
echo ///////////////////////////////////////////////
echo // Collects artifacts.
echo.

misc\ArtifactCollector\ArtifactCollector.exe . .\artifacts "%BuildIdentifier%" src\IL2C.Interop src\IL2C.Core src\IL2C.Build src\IL2C.Runtime misc\IL2C.toolchain

rem =========================================

rem .nuget\nuget.exe push -Source "IL2C" -ApiKey AzureDevOps .\artifacts\*.nupkg

echo.
echo Done.
echo.
