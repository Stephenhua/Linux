#!/bin/bash
#sh-2-- 测试数字是否为有效的浮点数字；

. ./sh-1.sh

validfloat()
{
    fvalue="$1"

    if [ ! -z $(echo $fvalue | sed 's/[^.]//g') ] ; then
     # s/ //g 表示删除；
     # [^.]表示一定有的字符；
        #提取小数点之前的部分；
        decimalPart="$(echo $fvalue | cut -d. -f1)"  
        #-d.指定字符段分隔符
        #-f1显示指定第一列字符

        fractionalPart="${favalue#*\.}"
        #\.输出单个字符；
        # ${file#*\.}表示删掉.左侧的字符；

        #先测试小数点左侧的整数部分；
        if [ ! -z $decimalPart ] ; then
            if ! validint  "$decimalPart" "" "" ; then
                return 1
            fi
        fi

        #测试小数部分

        if [ "${fractionalPart%${factionalPart#?}}" =  "-" ] ; then
            echo "invlaid floating-point number:" >&2
            return 1
        fi
        if [ "$fractionalPart" != "" ] ; then
            if ! validint  "$fractionalPart" "0" "" ; then
                return 1
            fi
        fi

    else
        if [ "$fvalue" = "-" ] ; then
            echo "invalid input" >&2
            return 1
        fi

        #检查最后剩余部分是否为整数

        if ! validint "$fvalue" "" "" ; then
            return 1
        fi

    fi

    return 0

}

if validfloat $1 ; then
  echo "$1 is a valid floating-point value"
fi
