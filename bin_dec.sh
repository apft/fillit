#!/bin/sh

values=$(grep -E "{.+/" parser.c | cut -d ' ' -f3)

for i in $values
do
	n=$i
	sign=${n:0:1}
	[ $sign -eq 1 ] && num=${n:1} || num=${n:0}
	num=$((2#$num))
	[ $sign -eq 1 ] && num=$(($num-32768))
	echo "$i : $num"
done
