#include <stdio.h>
#include <stdlib.h> 
int main()
{
	FILE *fptr1, *fptr2;
	char file[100], c;
	printf("Enter the file to Open For Reading : \n");
	scanf("%s", file);
	fptr1 = fopen(file, "r");
	if (fptr1 == NULL)
	{
		printf("Cannot Open File %s \n", file);
		exit(0);
	}
	printf("Enter the File Name to Open For Writing : \n");
	scanf("%s", file);
	fptr2 = fopen(file, "w");
	if (fptr2 == NULL)
	{
		printf("Cannot Open File %s \n", file);
		exit(0);
	}
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	printf("\nContents Copied to %s", file);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}