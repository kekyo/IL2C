@echo off
setlocal enabledelayedexpansion

rem if not exist ArtifactCollector\ArtifactCollector.exe (
rem     echo ArtifactCollector not found.
rem     echo Build il2c.sln first.
rem     exit /b 1
rem )

dotnet build --configuration Release il2c.sln

ArtifactCollector\ArtifactCollector.exe . .\artifacts IL2C.Interop IL2C.Core IL2C.Tasks IL2C.Runtime

rem .nuget\nuget.exe push -Source "IL2C" -ApiKey AzureDevOps .\artifacts\*.nupkg

echo.
echo Done.
echo.
