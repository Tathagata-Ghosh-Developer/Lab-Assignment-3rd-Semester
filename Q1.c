//Assignment - 7 - Programming Lab
/* Tathagata Ghosh - 2020ITB065 - HY*/

/*Q1. The power of any arbitrary square matrix A, denoted
as An , for a nonnegative integer n, is defined as the matrix
product of n copies of A. This means An= A · · · A | A is multiplied
n times. Note that, a matrix to the zeroth power is defined to be the identity
matrix of the same dimensions, i.e. A0 = I. Given the square matrix
A and the nonnegative integer n, write a program that can recursively compute An
involving minimal multiplications.*/

#include <stdio.h>
#include <stdlib.h>

int **solve(int **matrix, int size, int n) 
{
	if (n == 1) 
	{
		return matrix;
	}
	int **ans = (int**)malloc(size * sizeof(int));

	int **subans = solve(matrix, size, n - 1); //Recursive Subanswer

	for (int i = 0; i < size; i++) 
	{
		int *ptr = (int*)malloc(size * sizeof(int));
		for (int j = 0; j < size; j++) 
		{
			int x = 0;
			for (int k = 0; k < size; k++) 
			{
				int *temp = subans[k];
				x += matrix[i][k] * temp[j];
			}
			ptr[j] = x;
		}
		ans[i] = ptr;
	}
	return ans;

}
int main() 
{
	printf("----------------------------------------------------------------\n");
	printf("Enter the dimension of square matrix :");
	int d;
	scanf("%d", &d);
	printf("Enter the matrix :\n");
	int **matrix = (int**)malloc(d * sizeof(int));
	for (int i = 0; i < d; i++) 
	{
		int *ptr = (int*)malloc(d * sizeof(int));

		for (int j = 0; j < d; j++) 
		{
			scanf("%d", (ptr + j));
		}
		matrix[i] = ptr;
	}
	printf("Enter the power you want to calculate: ");
	int n;
	scanf("%d", &n);
	printf("----------------------------------------------------------------=\n");
	int **ans = solve(matrix, d, n);
	printf("The given matrix raised to the power %d is :\n", n);
	for (int i = 0; i < d; i++) 
	{
		int *ptr = ans[i];
		for (int j = 0; j < d; j++) 
		{
			printf("%d ", ptr[j]);
		}
		printf("\n");
	}
	return 0;
}