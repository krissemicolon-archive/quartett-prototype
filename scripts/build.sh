#!/bin/sh

meson build
ninja -C build
ln -s `pwd`/build/quartett `pwd`/quartett
