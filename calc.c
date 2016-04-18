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
