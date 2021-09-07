/*Programming Laboratory Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/* Q3. 2’s complement of a number is obtained by scanning it from right to left and
complementing all the bits after the first appearance of a 1. Thus 2's complement of
11100 is 00100. Write a C program to find the 2's complement of a binary number.*/

#include <stdio.h>

int main() 
{
	int n;
	
	printf("Enter a decimal number: \n");
	scanf("%d", &n);
	
	int nbits = 0;
	int x = n;
	while (n  > 0) 
	{
		n = n / 2;
		nbits++;
	}
	//printf("%d", nbits);

	int i = nbits - 1;
	int bin[nbits];
	while (x > 0) 
	{
		int rem = x % 2;
		bin[i] = rem;
		x = x / 2;
		i--;
	}

	printf("Binary Equivalent is: ");

	for (int i = 0; i < nbits; i++) 
	{
		printf("%d", bin[i]);
	}

	printf("\n");

	int f = 0;
	int comp[nbits];
	for (int i = nbits - 1; i >= 0; i--) 
	{
		if (f == 0) 
		{
			comp[i] = bin[i];
			if (bin[i] == 1) 
			{
				f = -1;
				continue;
			}
		}
		if (f == -1) 
		{
			comp[i] = !bin[i];
		}
	}

	printf("2's Complement is: ");
	for (int i = 0; i < nbits; i++) 
	{
		printf("%d", comp[i]);
	}
	printf("\n");
	return 0;
}