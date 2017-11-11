#include<stdio.h>
#include<string.h>
int main()
{
 char string[] = "Hello World!";
 string[5] = '\0';
 printf("%s\n", string);
}