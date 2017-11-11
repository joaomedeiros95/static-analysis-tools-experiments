/* Hello World program */

#include<stdio.h>

int divide(int x, int y) {
   return x / y; 
}

main()
{
	int result = divide(10, 0);
    printf("%d", result);
}