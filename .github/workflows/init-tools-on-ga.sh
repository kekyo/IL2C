#!/bin/sh
sudo -S apt-get update -y < /dev/null
sudo -S apt-get install build-essential cmake ninja-build mono-devel -y < /dev/null
