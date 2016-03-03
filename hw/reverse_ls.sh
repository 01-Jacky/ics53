#! /bin/bash

print_rev()
	num="$#"
	echo ${num}

for i in $@
do
	in_order=(`ls $i`)
	print_rev ${in_order[*]}
done
