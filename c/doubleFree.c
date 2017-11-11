/* Hello World program */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* ptr = (char*)malloc (128);
	short number = 1;
	free(ptr);
	free(ptr);
}