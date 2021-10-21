#!/bin/sh

# Required: .NET 5.0 SDK
#   https://dotnet.microsoft.com/download/dotnet/5.0

echo "Setup native binary toolchain ..."

apt update -y
apt install build-essential cmake ninja-build mono-devel -y

# `mono-devel` is required only running regression test. (net48 platform)

chmod 755 *.sh
