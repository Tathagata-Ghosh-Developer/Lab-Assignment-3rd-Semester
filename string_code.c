/*
Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
16/09/2021
*/

/*
Q1. Write a program to read the string of 0s and 1s from input terminal. Then do the
following.
a. Break the string into the substrings ending with 1 and of length of consecutive N
(>1) number of 0s or 1s. N can be 2, 3 and 4 taken as the input.
Example: Suppose you have a string “10000100100111110000100101000”. For
N=4, the sub strings will be 1, 0000, 1, 001, 001, 1111, 0000,1, 001, 01, 0000.
b. Count the frequency of each substring. Calculate the length of the string using
frequency and verify with the original string length.
Example: 1 occurs 2 times, 01 occurs 1 time, 001 occurs 3 times etc.
c. Replace each pattern substring with a character starting from A (for substring of
length 1), B (for substring with length 2) etc. and put the characters in a separate
file based on the position of the substring in the original string.
Example: 1 is replaced by A, 01 is replaced by B, 001 is replaced by C etc.
So, the final string will be: AEACCFEACBE
d. Calculate the length of the new string and calculate the % reduction of length.
Example: New string is of length 11. You can now calculate the % reduction of
length.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        printf("---File NOT Found---\n");
        exit(0);
    }
    else
    {
        char a[M];
        char res[M];
        fgets(a, M, fp);
        int l = strlen(a);

        int n;
        printf("Enter the value N : ");
        scanf("%d", &n);

        for(int i=l;i<=l+n;i++)
        {
            a[i]=a[l-1];
        }
        int freq[n+2];

        for(int i=0;i<n+2;i++)
        {
            freq[i]=0;
        }
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        printf("||Substrings: ");
        int i=0, cur = 0;
        while (i < l)
        {
            int j=i;
            while (j < i+n) 
            {
                printf("%c", a[j]);
                j += 1;
                if (a[i] == '1') 
                {
                    int pos = 1;
                    for(int k=j; k<i+n; k++)
                    {
                        if (a[k] == '0')
                        {
                            pos = 0;
                        }
                    }
                    if (!pos)
                    {
                        break;
                    }
                }
                if (a[i] == '0' && a[j-1] == '1')
                {
                    break;
                }
            }
            if (a[i] != a[j-1] || i == j-1)
            {
                freq[j-i-1] += 1;
            }
            else
            {
                freq[n+(a[i] - '0')] += 1;
            }
            res[cur] = (a[i] != a[j-1] || i==j-1) ? 'A' + (j-i-1) : 'A' + n + (a[i] - '0');
            cur += 1;
            i = j;
            if (i < l )
            {
                printf(",");
            }
        }
        printf("||\n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        int total = 0;
        printf("Substring   :   Frequency");
        for(int i=0; i<n+2; i++)
        {
            printf("\n ");
            if (i<n) 
            {
                for(int j=0; j<i; j++)
                {
                    printf("0");
                }
                printf("1");
                for(int j=0;j<n-i;j++)
                {
                    printf(" ");
                }
            }
            else
            {
                for(int j=0; j<n;j++)
                {
                    printf("%d",i-n);
                }
            }
                printf("         :\t   %d", freq[i] );
                total += freq[i]*(i<n ? i+1 : n);
        }
            printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
            printf("\nTotal length of substrings = %d\nOriginal string length= %d\n", total, l);
            printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
            printf("\nNew String: ");
            for(int i=0;i<cur; i++)
            {
                printf("%c",res[i]);
            }
            printf("\nLength of New String = %d\nPercentage reduction =%.2f\n", cur, (float)(total - cur) / total * 100);
            printf("\n----------------------------------------------------------------------------------------------------------------------------\n");
    }
        return 0;
}