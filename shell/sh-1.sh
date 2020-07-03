#! /bin/bash
#validint -- 验证整数输入，允许出现负数；

validint()
{
    number="$1"; min="$2";max="$3"

    if[ -z $number ] ; then
        echo "you did not enter anything .pleast enter a number.">&2
        return 1
    fi

    #第一个字符是否为负号；
    if [ "${number%${number#?}}" = "-" ] ; then
        testvalue="${number#?}"
    else
        testvalue="$number"
    fi
    nodigits="$(echo $testvalue | sed 's/[[:digit:]]//g')"

    if [ ! -z $nodigits ] ; then
        echo "Invaliud">&2
        return 1
    fi

    if [ ! -z $min ] ; then
        if [ "$number" -lt "$min" ] ; then   
            echo "value small"
            return 1
        fi
    fi

    if [ ! -z $max] ; then
        if [ "$number" -gt "$max" ] ; then
            echo "bigger value"
        fi
    fi

    return 0
}

if validint "$1" "$2" "$3" ; then
    echo "input is valid "

fi