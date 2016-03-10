#! /bin/bash

reg_ls=(`ls $1`)

printlast() {
	while (( $# - $i )) ; do
		shift
	done
	echo $1
}


i=1

printreverse() {
	for j in $@ ; do
		printlast $@
		((i++))
	done
}


printreverse ${reg_ls[*]}
