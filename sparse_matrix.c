/*Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/*Q5. Write a program in C to store a sparse matrix of order n x n efficiently which will take
less space than the normal way of storing a matrix.*/

#include <stdio.h>

int main()
{
	int n;
	printf("Enter the dimension of sparse matrix: ");
	scanf("%d", &n);
	int arr[n][n];
	int nonzero = 0;

	printf("Enter the elements of sparse matrix: \n");
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
        {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0)
            {
				nonzero++;
			}
		}
	}
    
	int sparse[nonzero][3];
	int k = 0;
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
        {
			if (arr[i][j] != 0)
            {
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k][2] = arr[i][j];
				k++;
			}
			if (k == nonzero) {
				break;
			}
		}
	}

	printf("row\tcol\tvalue\n");
	for (int i = 0; i < nonzero; i++)
    {
		printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
	}
}
