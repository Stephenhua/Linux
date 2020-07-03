#!/bin/bash

biggest=100
guess=0
gusses=0
number=$(( $RANDOM % $biggest + 1 ))
echo "Guess a number between 1 and $biggest"

while [ "$guess" -ne $number ] ; do
    /bin/echo -n "Guess?" ; read $guess

    if [ -z "$guess" ] ; then
        echo "Please enter a number .Use ^C to quit "
	continue
    fi

    if [ "$guess" -lt $number ] ; then
        echo "...bigger!"
    elif [ "guess" -gt $number ] ; then
        echo "... samaller!"
    fi
    guesses=$(( $guesses +1 ))
done

echo "Right, Guess $number in $guesses guesses"
exit 0
