#!/bin/bash
#fmt 文本实力工具；

while getopts "hw:" opt ; do
	case $opt in
		h ) hypeh=1    ;;
		w ) width="$OPEARG"
	esac
done

shift $(($OPTIND - 1))
nroff << EOF

.ll ${width:-72}
.na
.hy ${hyph:-0}
.pl 1
$(cat "$@")
EOF
exit 0

