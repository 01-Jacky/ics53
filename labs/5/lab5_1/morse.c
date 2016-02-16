#include <stdio.h>
#include <string.h>


char* m[128];
char ch[128];
void init() 
{
	for (int i = 0; i < 128; i++)
		ch[i] = i;
	int j = 0;
	m[0] = "";
	m[1] = "";
	m[2] = "";
	m[3] = "";
	m[4] = "";
	m[5] = "";
	m[6] = "";
	m[7] = "";
	m[8] = "";
	m[9] = "";
	m[10] = "";
	m[11] = "";
	m[12] = "";
	m[13] = "";
	m[14] = "";
	m[15] = "";
	m[16] = "";
	m[17] = "";
	m[18] = "";
	m[19] = "";
	m[20] = "";
	m[21] = "";
	m[22] = "";
	m[23] = "";
	m[24] = "";
	m[25] = "";
	m[26] = "";
	m[27] = "";
	m[28] = "";
	m[29] = "";
	m[30] = "";
	m[31] = "";
	m[32] = "";
	m[33] = "";
	m[34] = "";
	m[35] = "";
	m[36] = "";
	m[37] = "";
	m[38] = "";
	m[39] = "";
	m[40] = "";
	m[41] = "";
	m[42] = "";
	m[43] = "";
	m[44] = "";
	m[45] = "";
	m[46] = "";
	m[47] = "";

	m[48]= "- - - - -"; // 0
	m[49]=  ". - - - -"; // 1
	m[50]=  ". . - - -"; // 2
	m[51]= ". . . - -"; // 3
	m[52]= ". . . . -"; // 4
	m[53]= ". . . . ."; // 5
	m[54]= "- . . . ."; // 6
	m[55]= "- - . . ."; // 7
	m[56]= "- - - . . "; // 8
	m[57]= "- - - - ."; // 9

	m[58] = "";
	m[59] = "";
	m[60] = "";
	m[61] = "";
	m[62] = "";
	m[63] = "";
	m[64] = "";

	m[65]= ". -"; // a
	m[66]= "- . . ."; // b
	m[67]= "- . - ."; // c
	m[68]= "- . ."; // d
	m[69]= "."; // e
	m[70]= ". - ."; // f
	m[71]= "- - ."; // g
	m[72]= ". . . ."; // h
	m[73]= ". ."; // i
	m[74]= ". - - -"; // j
	m[75]= "- . -"; // k
	m[76]= ". - . ."; // l
	m[77]= "- -"; // m
	m[78]= "- ."; // n
	m[79]= "- - -"; // o
	m[80]= ". - - ."; // p
	m[81]= ". . - ."; // q
	m[82]= ".  . ."; // r
	m[83]= ". . ."; // s
	m[84]= "-"; // t
	m[85]= ". . -"; // u
	m[86]= ". . . -"; // v
	m[87]= ". - -"; // w
	m[88]= ". - . -"; // x
	m[89]= ". .  . ."; // y
	m[90]= ". . .  ."; // z
	m[91] = "";
	m[92] = "";
	m[93] = "";
	m[94] = "";
	m[95] = "";
	m[96] = "";
	m[97]= ". -"; // a
	m[98]= "- . . ."; // b
	m[99]= "- . - ."; // c
	m[100]= "- . ."; // d
	m[101]= "."; // e
	m[102]= ". - ."; // f
	m[103]= "- - ."; // g
	m[104]= ". . . ."; // h
	m[105]= ". ."; // i
	m[106]= ". - - -"; // j
	m[107]= "- . -"; // k
	m[108]= ". - . ."; // l
	m[109]= "- -"; // m
	m[110]= "- ."; // n
	m[111]= "- - -"; // o
	m[112]= ". - - ."; // p
	m[113]= ". . - ."; // q
	m[114]= ".  . ."; // r
	m[115]= ". . ."; // s
	m[116]= "-"; // t
	m[117]= ". . -"; // u
	m[118]= ". . . -"; // v
	m[119]= ". - -"; // w
	m[120]= ". - . -"; // x
	m[121]= ". .  . ."; // y
	m[122] = ". . .  ."; // z
	m[123] = "";
	m[124] = "";
	m[125] = "";
	m[126] = "";
	m[127] = "";
}

int count_spaces(char* string)
{
	char* sp = string;
	int cnt = 0;
	while(*sp == ' ')
	{
		cnt++;
		sp++;
	}
	return cnt;
}

void print_letter(char* morse)
{
	for (int i = 0;i < 128;i++)
		if (strcmp(morse, m[i]) == 0)
		{
			printf("%c", ch[i]);
			return;
		}
}

char peek(char* str) 
{
	return *(str + 1);
}

void split_morse(char* morse)
{
	char* sp = morse;
	while(*sp != '\n' && *sp != EOF)
	{
		switch(*sp)
		{
			case '-':
			case '.':
				break;
			case ' ':
				switch(count_spaces(sp))
				{
					case 1:
						break;
					case 3:
						*sp = '\0';
						print_letter(morse);
						sp += 2;
						morse = sp + 1;
						print_letter(morse);
						break;
					case 7:
						*sp = '\0';
						print_letter(morse);
						printf(" ");
						sp += 6;
						morse = sp + 1;
						print_letter(morse);
						break;
				}
		}
		sp++;
		if (*sp == EOF || *sp == '\n')
		{
			char temp = *sp;
			*sp = '\0';
			print_letter(morse);
			*sp = temp;
		}
	}
}

void m_to_a()
{
	char morse[1024];
	fgets(morse, 1024, stdin);
	split_morse(morse);
}

void a_to_m()
{
	char c;
	while((c = getchar()) != '\n')
	{
		switch(c) {
			case ' ':
				printf("    ");
				break;
			default:
				printf("%s", m[c]);
				break;
		}
		printf("   ");
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	init();
	if (argc == 2)
	{
		if(strcmp(argv[1], "m")==0)
			m_to_a();
		if(strcmp(argv[1], "a")==0)
			a_to_m();
	}
	return 0;
}
