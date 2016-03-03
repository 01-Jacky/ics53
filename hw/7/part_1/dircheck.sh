#! /bin/bash

for d in $@
do
	if [ -d $d ]
	then
		echo $d:
		# i) display a count of the number of subdirectories anywhere under this directory
		dircount=( `find $d -type d ! -path $d | wc -l` )
		echo $dircount 

		# ii) display a count of the number of files in the directory (you may count just the files 
		#	in this immediate directory or traverse the entire directory tree and count all in and below)
		filcount=( `find $d -type f | wc -l` )
		echo $filcount

		# iii) list all of the files in and below the directory that are zero length (you may use the 
		#	'find' command for this)
		find $d -size 0

		# iv) use 'du' to display the total amount of storage space (bytes or blocks - your choice) used
		#	by this directory (including all files and directories contained within)
		du -c $d | grep total

		# v) to test your script, you should create some subdirectories, some files that are zero length,
		#	using touch, and some files that are not zero length using vi, output redirection, or cp.

		# vi) Example of use
		#	$ dircheck ~/hw ~/bin
		echo 
	fi
done
