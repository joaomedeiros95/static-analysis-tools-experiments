#include<stdio.h>
#include<string.h>
int main()
{
 char string[] = "Some String\0";
 int min, max;
 max = sizeof(string) / sizeof(string[0]);

 for (min = 0; min <= max; min++) {
 	printf("%c\n", string[min]);
 }
}