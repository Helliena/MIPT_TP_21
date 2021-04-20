#!/bin/bash
dr=$1
ext=$2
fld=$3
arc=$4
mkdir $fld
find $dr -name "*.$ext" -exec cp {} $fld \;
for file in $fld/*
do 
 tar -rf $arc.tar.gz $file
done 
echo "done"
