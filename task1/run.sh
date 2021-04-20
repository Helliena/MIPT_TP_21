#!/bin/bash
dr=$1
ext=$2
fld=$3
arc=$4
mkdir $dr/$fld
find $dr -name "*.$ext" -exec cp {} $dr/$fld \;
cd
cd $dr
tar -czf $arc.tar.gz $fld
echo "done"
