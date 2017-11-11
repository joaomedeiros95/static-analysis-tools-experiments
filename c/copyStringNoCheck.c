/* Hello World program */

#include<stdio.h>
#include<string.h>

void manipulate_string(char* string){
	char buf[100];
	strcpy(buf, string);
	strcat(buf, "Ola Mundo");
	printf("%s\n", buf);

	char sprintfbuf[20];
	sprintf(sprintfbuf, "Hello World!");

	char copied[10];
	strncpy ( copied, sprintfbuf, sizeof(copied) );

	strncat(copied, buf, 6);
	char snbuf[20];
	snprintf(snbuf, 10, "ola mundo");
	printf("%s\n", snbuf);
}

void openFile() {
	FILE *fp;
   char str[60];

   /* opening file for reading */
   fp = fopen("example.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
   }
   if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      puts(str);
   }
   fclose(fp);
}

int main()
{
	char result[] = "Hello World!!!";
    manipulate_string(result);

    char buffer[10];
    gets(buffer);

    printf("%s\n", buffer);

    openFile();
}