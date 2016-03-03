#! /bin/sh

path=(`echo $PATH | tr ":" " "`)
for i in $@
do
	for f in ${path[*]}
	do
		if [ -f $f/$i ]
		then
			echo $f/$i
		fi
	done
done
