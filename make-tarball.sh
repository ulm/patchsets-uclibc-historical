#!/bin/bash

if [[ $# -lt 2 ]] ; then
	echo "Usage: $0 <uclibc ver> <patch ver>"
	exit 1
fi
uver=$1
pver=$2

if [[ ! -d ./${uver} ]] ; then
	echo "Error: ${uver} is not a valid uclibc ver"
	exit 1
fi

rm -rf tmp
rm -f uClibc-${uver}-*.tar.bz2

mkdir -p tmp/patch
cp -r ../README* ${uver}/*.patch tmp/patch/ || exit 1

if [[ -d ${uver}/math ]] ; then
	mkdir tmp/patch/math
	cp -r ${uver}/math/*.patch tmp/patch/math/ || exit 1
	if [[ -d ${uver}/math/libm ]] ; then
		mkdir tmp/patch/math/libm
		cp -r ${uver}/math/libm/*.c tmp/patch/math/libm/ || exit 1
	fi
fi

#find tmp -type f -a ! -name 'README*' | xargs bzip2

tar -jcf uClibc-${uver}-patches-${pver}.tar.bz2 \
	-C tmp patch || exit 1
rm -r tmp

du -b uClibc-${uver}-*.tar.bz2
