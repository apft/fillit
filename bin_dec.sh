#!/bin/sh

old_IFS=$IFS
IFS=$'\n'

for i in $(grep -E '{.+/' parser.c)
do
	echo "============="
	echo $i | xargs
	tile=$(echo $i | cut -d ' ' -f3)
	shif=$(echo $i | cut -d ' ' -f4)
	for j in $tile $shif
	do
		n=$j
		sign=${n:0:1}
		[ $sign -eq 1 ] && num=${n:1} || num=${n:0}
		num=$((2#$num))
		#[ $sign -eq 1 ] && num=$(($num-32768))
		echo "$j : $num"
	done
done
IFS=${old_IFS}
