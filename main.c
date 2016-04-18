#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()

{
	char op;
	float w;
	printf("\nCalculator(enter 'x' to exit)");
	for(;;)
	{
		op=get_operator();
		if(op=='x')
			exit(1);
		else 
			if(op=='f')
			{
			w = get_float();
			printf("\nYou entered %f", w);
			}
	}
}
