#!/bin/bash
#命令统计:通过一个简单的脚本，统计粗当前path中的多少可能的执行命令；
#更新
IFS=":";
count=0 ; nonex=0
for directory in $PATH ; do 
    if [ -d "$directory" ] ; then
        for command in "$directory"/* ; do 
            if [ -x "$command" ] ; then
                count="$(( $count + 1 ))"
            else
                nonex="$(( $nonex +1 ))"
            fi
        done
    fi
done

echo "$count commands ,and $nonex entries that weren't exectualble"

exit 0

