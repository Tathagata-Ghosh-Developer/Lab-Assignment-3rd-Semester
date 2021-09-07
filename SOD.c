/*Programming Laboratory Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/* Q1. Write a C program to find the sum of individual digits of a positive integer.*/

#include <stdio.h>

int main() 
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	int t = n;
	int sum = 0;
	while (t > 0) 
	{
		int d = t % 10;
		sum = sum + d;
		t /= 10;
	}

	printf("Sum of digits of %d = %d \n", n, sum);
	return 0;
}