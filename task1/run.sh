#!/bin/bash
dr=$1
ext=$2
fld=$3
arc=$4
mkdir $fld
find $dr -name "*.$ext" -exec cp --backup=numbered {} $fld \;
tar -czf $arc $fld
echo "done"
