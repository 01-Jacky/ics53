#include <stdio.h>
#include <string.h>
#include <ctype.h>
char peekc()
{
	char c = getchar();
	ungetc(c, stdin);
	return c;
}

long long stack[1024] = {0};
int top = -1;

long long pop() 
{
	if (top > -1)
		return stack[top--];
	else
		return 0;
}

void push(long long num)
{
	stack[++top] = num;
}

void swap() 
{
	long long temp = stack[top];
	stack[top] = stack[top-1];
	stack[top-1] = temp;
}

void add() 
{
	long long sum = pop() + pop();
	push(sum);
}

void sub()
{
	long long temp = pop();
	long long diff = pop() - temp;
	push(diff);
}

void mul()
{
	long long prod = pop() * pop();
	push(prod);
}

void div()
{
	long long temp = pop();
	long long quo = pop() / temp;;
	push(quo);
}

void dup()
{
	push(stack[top]);
}

void print_top()
{
	printf("%lld\n", stack[top]);
}


long long make_num(char c)
{
	ungetc(c, stdin);
	long long num;
	scanf("%lld", &num);
	return num;
}

int main()
{
	char c;
	while ((c = getchar()) != '\n')
	{
		switch (c)
		{
			case ' ':
			case '\t':
				// skip white spaces
				break;
			case '+':
				// call add
				add();
				break;
			case '-':
				//check if negative number or minus
				switch(peekc())
				{
					case ' ':
					case '\t':
						sub();
						break;
					default:
						push(make_num(getchar()) * -1);
						// make number
						break;
				}		
				break;
			case '/':
				// call divide
				div();
				break;
			case '*':
				// call muliply
				mul();
				break;
			case 'p':
				// print top of stack
				print_top();
				break;
			case 's':
				// swap top 2
				swap();
				break;
			case 'd':
				// duplicate top of stack
				dup();
				break;
			default:
				push(make_num(c));
				// make number
				break;
		}
	}	
	return 0;
}
