/* Hello World program */

#include<stdio.h>

int divide(int x) {
   return x / 0; 
}

main()
{
	int result = divide(10);
    printf("%d", result);
}