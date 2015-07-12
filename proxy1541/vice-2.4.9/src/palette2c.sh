#!/bin/sh

# this file makes a header file out of a .vpl

HEADERFILENAME=$1
ARRAYNAME=$2

echo Generating $HEADERFILENAME
echo >$HEADERFILENAME "/* Autogenerated file, do not edit */"
echo >>$HEADERFILENAME ""
echo >>$HEADERFILENAME "$ARRAYNAME = {"

entries=0
while read data
do
    if [ ${#data} -ne 0 ]; then
        if test x"${data:0:1}" != "x#"; then
            red=${data:0:2}
            green=${data:3:2}
            blue=${data:6:2}
            dither=${data:9:1}
            echo >>$HEADERFILENAME "    0x$red, 0x$green, 0x$blue, 0x$dither,"
            entries=`expr $entries + 1`
        fi
    fi
done
echo >>$HEADERFILENAME "    $entries };"