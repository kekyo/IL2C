#!/bin/sh

echo "Setup native binary toolchain ..."

apt-get update -y
apt-get install build-essential cmake ninja-build -y

chmod 755 *.sh
