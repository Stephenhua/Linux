#!/bin/bash

if read -t 5 -p "Please enter your name: " name
then
	echo "Hello $name ,welcome to your sccript"
else
	echo
	echo "Sorry too slow"

fi


