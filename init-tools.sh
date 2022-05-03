#!/bin/sh

# Required: .NET 6.0 SDK
#   https://dotnet.microsoft.com/en-us/download/dotnet/6.0

echo "Setup native binary toolchain ..."

apt update -y
apt install build-essential cmake ninja-build mono-devel -y

# `mono-devel` is required only running regression test. (net48 platform)

chmod 755 *.sh
