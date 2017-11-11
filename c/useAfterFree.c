#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *string = (char*) malloc(15 * sizeof(char));
    snprintf(string, 15 * sizeof(char), "Hello World");

    free(string);

    printf("%s\n", string);

    return 0;
}