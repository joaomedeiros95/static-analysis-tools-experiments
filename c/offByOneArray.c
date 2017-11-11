#include<stdio.h>
#include<string.h>
int main()
{
 int numbers[] = {1, 2, 3, 4, 5};
 int min, max;
 max = sizeof(numbers) / sizeof(numbers[0]);

 for (min = 0; min <= max; min++) {
 	printf("%d\n", numbers[min]);
 }
}