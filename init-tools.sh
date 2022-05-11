#!/bin/sh

# `mono-devel` is required only running regression test. (net48 platform)

echo "Setup native binary toolchain ..."

sudo apt update -y
sudo apt install build-essential cmake ninja-build mono-devel -y

#curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin -c 2.1
#curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin -c 2.2
#curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin -c 3.1
#curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin -c 5.0
#curl -sSL https://dot.net/v1/dotnet-install.sh | bash /dev/stdin -c 6.0

#export PATH=$HOME/.dotnet:$PATH
#export DOTNET_HOME=$HOME/.dotnet

#echo "You have to set environment variables in your sh profile:"

#echo "export PATH=$HOME/.dotnet:$PATH"
#echo "export DOTNET_HOME=$HOME/.dotnet"

