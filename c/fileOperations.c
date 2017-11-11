/* Hello World program */

#include<stdio.h>
#include<string.h>

void read_one() {
	FILE *fp;

	fp = fopen("example.txt", "r");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
	fclose(fp);
}

void read_two() {
	char buff[255];
	FILE *fp;

	fscanf(fp, "%s", buff);
	printf("%s\n", buff);
}

void read_three() {
	char buff[255];
	FILE *fp;

	fp = fopen("example.txt", "r");
	fscanf(fp, "%s", buff);
	printf("%s\n", buff);
}

void read_four() {
	char buff[255];
	FILE *fp;

	fp = fopen("example.txt", "r");
	fclose(fp);
	fscanf(fp, "%s", buff);
	printf("%s\n", buff);
}


int main()
{
	read_one();
	read_two();
	read_three();
	read_four();
}