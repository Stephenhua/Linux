#!/bin/bash
#创建多个用户账户

input="users.csv"
while IFS=',' read -r userid name
do
	echo "adding $userid"
	useradd -c "name" -m $userid
done < "$input"
