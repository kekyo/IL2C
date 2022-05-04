#!/bin/sh

VERSION=0.4.100

rm -rf artifacts
mkdir artifacts

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Interop"
echo ""

dotnet pack --configuration Release src/IL2C.Interop/IL2C.Interop.csproj
cp src/IL2C.Interop/bin/Release/IL2C.Interop.*.nupkg artifacts/

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Core"
echo ""

dotnet pack --configuration Release src/IL2C.Core/IL2C.Core.csproj
cp src/IL2C.Core/bin/Release/IL2C.Core.*.nupkg artifacts/

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Runtime"
echo ""

.nuget/nuget pack -Prop version=${VERSION} -OutputDirectory artifacts src/IL2C.Runtime/IL2C.Runtime.nuspec 

echo ""
echo "///////////////////////////////////////////////"
echo "// Build IL2C.Build"
echo ""

dotnet pack --configuration Release src/IL2C.Build/IL2C.Build.csproj
cp src/IL2C.Build/bin/Release/IL2C.Build.*.symbols.nupkg artifacts/

echo ""
echo "///////////////////////////////////////////////"
echo "// Build Arduino library"
echo ""

mkdir artifacts/Arduino
cp -R src/IL2C.Runtime/include/*.h artifacts/Arduino/src/
cp -R src/IL2C.Runtime/src/*.h artifacts/Arduino/src/
cp -R src/IL2C.Runtime/src/*.c artifacts/Arduino/src/

sed 's/{version}/${VERSION}/g' Arduino.properties > artifacts/Arduino/library.properties

echo ""
echo "Done."
echo ""
