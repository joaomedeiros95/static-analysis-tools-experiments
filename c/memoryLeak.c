/* Hello World program */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void with_malloc() {
	char *string = (char*) malloc(20 * sizeof(char));
    snprintf(string, 20 * sizeof(char), "Hello World"); 

    printf("%s\n", string);
}

void with_calloc() {
	char *string = (char*) calloc(20, sizeof(char));
    snprintf(string, 20 * sizeof(char), "Hello World2"); 

    printf("%s\n", string);
}

void with_realloc() {
	char *string = (char*) calloc(20, sizeof(char));
    snprintf(string, 20 * sizeof(char), "Hello World3");

	char *another_string;
    another_string = (char*) realloc(string, 15 * sizeof(char));
    snprintf(string, 15 * sizeof(char), "Hello World4"); 

    printf("%s\n", another_string);
}

int main()
{
    with_malloc();
    with_calloc();
    with_realloc();
    return 0;
}