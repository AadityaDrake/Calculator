#include <stdio.h>
#include "calc.h"

char get_operator()
{
	char string[80];
	int i;
	printf("\nEnter Command> ");
	//scanf("%c", &a);
	//return a;
	scanf("%s", string);
	for(i=0; is_whitespace(string[i]) && string[i] == '\0'; i++);
	return string[i];
}

float get_float()
{
	float q;
	printf("\nEnter an real number (x[.y])> ");
	scanf("%f", &q);
	return q;
}

float add(float v, float r)
{
	float c = v+r;
	return c;
}

float subtract(float a, float b)
{
	float c = a-b;
	return c;
}

float multiply(float a, float b)
{
	float c = a*b;
	return c;
}

float divide(float a, float b)
{
	float c = a/b;
	return c;
}

int valid_operator(char op)
{
	if(op == 'x' || op == 'f' || op =='+' || op == '-' || op == '/' || op == '*')
		return 1;
	else
	{
		printf("\nInvalid Command , Please Input Again\n");
		return 0;
	}
}

int is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n') {
		return 1;
	} else {
		return 0;
	}
}
