//Parsing input


/*
must deal with erroneous input
must break apart strings into pieces
	pieces are often called words or tokens
		token.. an atomic unit of a language

decide on format of input
	eg bash commands
describe input using regular expressions
	ALPHA[a-zA-Z_]
	NUMERIC[0-9]
	WORD {ALPHA}({ALPHA}|{NUMERIC})* ... * means 0 or more, | means OR
	OPERATOR [<>&|]


all the same:
char s1[4] = {'a', 'b', 'c', '\0'};
char s2[4] = "abc";
char s3[] = "abc";
*/
