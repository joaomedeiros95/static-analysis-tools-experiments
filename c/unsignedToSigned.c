#include<stdio.h>
int main()
{
 unsigned int number;
 number = -1;

 unsigned int number2;
 int negativeNumber = -1;

 number2 = negativeNumber;
 
 printf("%u", number);
 printf("%u", number2);
 return 0;
}