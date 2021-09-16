/*
Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
16/09/2021
*/

/*
Q2. Do the addition and subtraction of two NxN sparse matrices using the efficient
representation of the matrix done in the previous Assignment 1.
*/

#include <stdio.h>

    void add(int nz1, int nz2, int sparse1[nz1][3], int sparse2[nz2][3]) 
    {
        int sparse3[50][3];
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < nz1 && i2 < nz2) 
        {
            if (sparse1[i1][0] < sparse2[i2][0]) 
            {
                sparse3[i3][0] = sparse1[i1][0];
                sparse3[i3][1] = sparse1[i1][1];
                sparse3[i3][2] = sparse1[i1][2];
                i3++;
                i1++;
            }
            else if (sparse1[i1][0] > sparse2[i2][0]) 
            {
                sparse3[i3][0] = sparse2[i2][0];
                sparse3[i3][1] = sparse2[i2][1];
                sparse3[i3][2] = sparse2[i2][2];
                i3++;
                i2++;
            }
            else if (sparse1[i1][1] < sparse2[i2][1]) 
            {
                sparse3[i3][0] = sparse1[i1][0];
                sparse3[i3][1] = sparse1[i1][1];
                sparse3[i3][2] = sparse1[i1][2];
                i3++;
                i1++;
            }
            else if (sparse1[i1][1] > sparse2[i2][1]) 
            {
                sparse3[i3][0] = sparse2[i2][0];
                sparse3[i3][1] = sparse2[i2][1];
                sparse3[i3][2] = sparse2[i2][2];
                i3++;
                i2++;
            }
            else 
            {
                if (sparse1[i1][2] + sparse2[i2][2] != 0) 
                {
                    sparse3[i3][0] = sparse1[i1][0];
                    sparse3[i3][1] = sparse1[i1][1];
                    sparse3[i3][2] = sparse1[i1][2] + sparse2[i2][2];
                    i1++;
                    i2++;
                    i3++;
                }
                else 
                {
                    i1++;
                    i2++;
                }
            }
        }
        while (i1 < nz1) 
        {
            sparse3[i3][0] = sparse1[i1][0];
            sparse3[i3][1] = sparse1[i1][1];
            sparse3[i3][2] = sparse1[i1][2];
            i3++;
            i1++;
        }
        while (i2 < nz2) 
        {
            sparse3[i3][0] = sparse2[i2][0];
            sparse3[i3][1] = sparse2[i2][1];
            sparse3[i3][2] = sparse2[i2][2];
            i3++;
            i2++;
        }
        printf("Sparse Matrix after Addition:\n");
        printf("row\tcol\tvalue\n");
        for (int i = 0; i < i3; i++) 
        {
            printf("%d\t%d\t%d\n", sparse3[i][0], sparse3[i][1], sparse3[i][2]);
        }
    }

    void subtract(int nz1, int nz2, int sparse1[nz1][3], int sparse2[nz2][3]) 
    {
        int sparse3[50][3];
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < nz1 && i2 < nz2) 
        {
            if (sparse1[i1][0] < sparse2[i2][0]) 
            {
                sparse3[i3][0] = sparse1[i1][0];
                sparse3[i3][1] = sparse1[i1][1];
                sparse3[i3][2] = sparse1[i1][2];
                i3++;
                i1++;
            }
            else if (sparse1[i1][0] > sparse2[i2][0]) 
            {
                sparse3[i3][0] = sparse2[i2][0];
                sparse3[i3][1] = sparse2[i2][1];
                sparse3[i3][2] = -sparse2[i2][2];
                i3++;
                i2++;
            }
            else if (sparse1[i1][1] < sparse2[i2][1])
            {
                sparse3[i3][0] = sparse1[i1][0];
                sparse3[i3][1] = sparse1[i1][1];
                sparse3[i3][2] = sparse1[i1][2];
                i3++;
                i1++;
            }
            else if (sparse1[i1][1] > sparse2[i2][1])
            {
                sparse3[i3][0] = sparse2[i2][0];
                sparse3[i3][1] = sparse2[i2][1];
                sparse3[i3][2] = -sparse2[i2][2];
                i3++;
                i2++;
            }
            else 
            {
                if (sparse1[i1][2]  != sparse2[i2][2])
                {
                    sparse3[i3][0] = sparse1[i1][0];
                    sparse3[i3][1] = sparse1[i1][1];
                    sparse3[i3][2] = sparse1[i1][2] - sparse2[i2][2];
                    i1++;
                    i2++;
                    i3++;
                }
                else
                {
                    i1++;
                    i2++;
                }
            }

        }
        while (i1 < nz1)
        {
            sparse3[i3][0] = sparse1[i1][0];
            sparse3[i3][1] = sparse1[i1][1];
            sparse3[i3][2] = sparse1[i1][2];
            i3++;
            i1++;
        }
        while (i2 < nz2)
        {
            sparse3[i3][0] = sparse2[i2][0];
            sparse3[i3][1] = sparse2[i2][1];
            sparse3[i3][2] = -sparse2[i2][2];
            i3++;
            i2++;
        }
        
        printf("Sparse Matrix after Subtraction:\n");
        printf("row\tcol\tvalue\n");
        for (int i = 0; i < i3; i++) 
        {
            printf("%d\t%d\t%d\n", sparse3[i][0], sparse3[i][1], sparse3[i][2]);
        }
    }

    int main() 
    {
        int n = 5;
        printf("Enter the dimension of matrix 1: ");
        scanf("%d", &n);
        int arr1[n][n];
        int nonzero1 = 0;
        printf("Enter the elements of matrix 1: \n");
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                scanf("%d", &arr1[i][j]);
                if (arr1[i][j] != 0) 
                {
                    nonzero1++;
                }
            }
        }

        int arr2[n][n];
        int nonzero2 = 0;
        printf("Enter the elements of matrix 2: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr2[i][j]);
                if (arr2[i][j] != 0) 
                {
                    nonzero2++;
                }
            }
        }

        int sparse1[nonzero1][3];
        int k = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (arr1[i][j] != 0) 
                {
                    sparse1[k][0] = i;
                    sparse1[k][1] = j;
                    sparse1[k][2] = arr1[i][j];
                    k++;
                }
                if (k == nonzero1) 
                {
                    break;
                }
            }
        }

        int sparse2[nonzero2][3];
        k = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (arr2[i][j] != 0) 
                {
                    sparse2[k][0] = i;
                    sparse2[k][1] = j;
                    sparse2[k][2] = arr2[i][j];
                    k++;
                }
                if (k == nonzero2) 
                {
                    break;
                }
            }
        }

        printf("Sparse Matrix Representation of 1st Matrix: \n");
        printf("row\tcol\tvalue\n");

        for (int i = 0; i < nonzero1; i++) 
        {
            printf("%d\t%d\t%d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);
        }

        printf("Sparse Matrix Representation of 2nd Matrix: \n");
        printf("row\tcol\tvalue\n");

        for (int i = 0; i < nonzero2; i++)
        {
            printf("%d\t%d\t%d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);
        }

        int x;

        printf("Enter 1 for addition and 2 for subtraction: \n");
        scanf("%d", &x);

        switch(x) 
        {
            case 1: add(nonzero1, nonzero2, sparse1, sparse2);
                    break;
            case 2: subtract(nonzero1, nonzero2, sparse1, sparse2);
                    break;
            default: printf("Enter a valid choice!");
        }
        return 0;
    }
