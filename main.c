#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()

{
	char op;
	float w,f1,f2;
	printf("\nCalculator(enter 'x' to exit)");
	for(int i=0;;i++)
	{
		op=get_operator();
		if(op == 'x')
			exit(1);
		else
			if(op == 'f')
			{
				w = get_float();
				printf("\nYou Entered %f", w);
			}
			else
				if(op == '+')
				{
					f1 = get_float();
					f2 = get_float();
					printf ("%f", add(f1,f2));
				}
				else
					if(op == '-')
					{
						f1 = get_float();
						f2 = get_float();
						printf ("%f", subtract(f1,f2));
					}
					else
						if(op == '*')
						{
							f1 = get_float();
							f2 = get_float();
							printf ("%f", multiply(f1,f2));
						}
						else
							if(op == '/')
							{
								f1 = get_float();
								f2 = get_float();
								printf ("%f", divide(f1,f2));
							}
	}
}
