//Assignment - 7 - Programming Lab
/* Tathagata Ghosh - 2020ITB065 - HY*/

/*Q3.     Write a C program to read a binary file. Explore
the functions available in C library to read the data.  Take the
input as a.out file created after compilation of a C program after doing
addition of two integers.*/

#include <stdio.h>

int main() 
{
	char buffer[10000];
	FILE *ptr;

	ptr = fopen("a.out", "rb"); // r for read, b for binary
	if (ptr == NULL) 
	{
		printf("Error! File could not be opened.");
		return 0;
	}
	printf("Using fread()\n");

	//Function to read binary file and store it in
	fread(buffer, sizeof(buffer), 1, ptr);

	int i = 0;
	while (buffer[i] != EOF) 
	{
		printf("%x", buffer[i]);
		i++;
	}

	printf("\n");
	fclose(ptr);
	return 0;
}