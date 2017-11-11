/* Hello World program */

#include<stdio.h>
#include<string.h>

void manipulate_string(char* string){
	char buf[10];
	strcpy(buf, string);
	printf("%s", buf);
}

int main()
{
	char result[] = "Hello World!!!";
    manipulate_string(result);
}