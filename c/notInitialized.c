/* Hello World program */

#include<stdio.h>
#include<string.h>

void manipulate_string(){
	char *buf;
	char string[100];
	buf = string;
	char source[100] = "Hello World";

	strcat(buf, source);
	printf("%s", buf);
}

int main()
{
    manipulate_string();
}