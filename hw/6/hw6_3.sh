echo "3a. print all lines containing integer literals in the files *.c in the current directory"
echo 
grep [0-9] *.c
echo 
echo

echo "3b. print all calls to printf in the files *.h and *.c"
echo
grep "printf" *.[hc]
echo
echo

echo "3c. delete all blank lines from a file called foo.c (actually modify foo.c, but be careful about I/O redirection as cat < foo > foo will not work as you might like it to)."
echo
sed /^$/d foo.c > tmp && mv tmp foo.c
echo
echo

echo "3d. move all files anywhere below your home directory that have the extension '.o' or '.out' into a specal directory called '.trash' contained in your home directory. Be careful not to move files from .trash to .trash (hint: use find). Also, you should create .trash before executing your command."
echo
mv *.o *.out .trash
echo
echo

echo "3e. list the names of files in all directories named 'bin' on the local machine (hint: use find)"
echo
find / -name bin -exec ls {} \;
echo
echo

echo "3f list the names of all files larger than 20 blocks in your home directory (hint: use find)"
echo
find ~ -size 20
echo
echo
