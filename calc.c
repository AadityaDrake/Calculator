#include <stdio.h>
char get_operator()
{
	char a;
	printf("\nEnter Command> ");
	scanf("%c", &a);
	return a;
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
		return 0;
}
