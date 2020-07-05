#!/bin/bash
name=$(basename $0)
echo
echo "The script name is :$name "
echo
count=1
for param in "$@"
do
	echo "\$@ Parameter # $count = $param"
	count=$[ $count + 1 ]
done

count2=1

while [ -n "$1" ]
do
	echo "Parameter #$count2 = $1"
	count2=$[ $count2 + 1 ]
	shift
done
