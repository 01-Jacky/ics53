#! /bin/bash

recur_in() 
{
	if [ -d $1 ]
	then
		echo $1
		in_d=(`ls -A $1`)
		for f in ${in_d[*]}
		do
			if [ -d $1/$f ]
			then
				recur_in $1/$f
			else
				echo $1/$f
			fi
		done
	fi
}

type_d() 
{
	for i in $@ ; do
		if [ -d $i ] ; then
			echo $i
		fi
	done
}

type_f() 
{
	for i in $@ ; do
		if [ -f $i ] ; then
			echo $i
		fi
	done
}

split_dir()
{
	with_dirs=(` echo $1 | tr '/' ' '`)
	echo ${with_dirs[*]}
}

remove_leading_dir()
{
	while (( $# - 1 )) ; do
		shift
	done
	echo $1
}

find_name() 
{
	name=$1
	shift
	for i in $@ ; do
		splitted=(`split_dir $i`)
		new_dir=(`remove_leading_dir ${splitted[*]}`)
		if [[ $new_dir == $name ]] ; then
			echo $i	
		fi
	done
}


do_options()
{
	is_print=0
	is_exec=0
	is_on=1
	if [ $# -eq 0 ] ; then
		is_print=1
	else
		while (( $# )) && [[ $is_on -eq 1 ]] ; do
			case "$1" in 
				-name)
					if [ $2 ] ; then
						new_list="$2 ${the_list[*]}"
						the_list=(`find_name ${new_list}`)
					else
						echo $0: $1: requires additional arguments
						exit
					fi
					shift
					;;
				-type)
					if [ $2 ] ; then 
						if [ $2 == "d" ] || [ $2 == "f" ] ; then
							case "$2" in
								d)	
									# echo d
									the_list=(`type_d ${the_list[*]}`)
									;;
									
								f)
									# echo f
									the_list=(`type_f ${the_list[*]}`)
									;;
							esac
						else
							echo $0: $1: $2: unknown type
							exit
						fi
					else
						echo $0: $1: requires additional arguments
						exit
					fi
					shift
					;;
				-print)
					is_print=1 
					;;
				-exec)
					is_exec=1
					is_on=0
					;;
					-*)
					echo $0: $1: unknown primary or operator
					exit
					;;

			esac
			shift
		done
	fi
	if [ $is_print -eq 1 ] ; then
		for li in ${the_list[*]} ; do
			echo $li
			if [ $is_exec -eq 1 ] ; then
				to_exec=(`echo $@ | sed s@{}@$li@`)
				${to_exec[*]}
			fi
		done
	else
		for il in ${the_list[*]} ; do
			if [ $is_exec -eq 1 ] ; then
				to_exec=(`echo $@ | sed s@{}@$il@`)
				${to_exec[*]}
			fi
		done
	fi
}


DIRS_LIST=""
OPTIONS=""
#get directories
while [[ $1 != -* ]] && (( $# )); do
	DIRS_LIST="$DIRS_LIST $1"
	shift
done

#get options
while (( $# )) ; do
	OPTIONS="$OPTIONS $1"
	shift
done

for d in ${DIRS_LIST[*]} ; do
	if [ -d $d ] ; then
		the_list=(`recur_in $d`)
		do_options $OPTIONS
	else
		echo $0: $d: No such file or directory
	fi
done




