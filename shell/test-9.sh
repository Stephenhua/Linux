#!/bin/bash
#查找可执行文件

IFS=:
for folder in $PATH
do
	echo "$solder:"
	for file in $folder/*
	do
		if [ -x $file ]
		then
			echo "   $file"
		fi
	done
done

