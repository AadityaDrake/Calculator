#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()

{
	char op;
	printf("Calculator(enter 'x' to exit)\n");
	for(;;)
	{
		op=get_operator();
		if(op=='x')
			exit(1);
	}
}
