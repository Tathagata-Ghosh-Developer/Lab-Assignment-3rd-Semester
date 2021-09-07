/*Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/*Q2.Given an array of n integers, write a C program for reversing the contents of the array
without using another array.*/

#include<stdio.h>

int main()
{
    printf("Enter the size of the array : ");
    int n;
    scanf( "%d",&n );
    int a[n];
    printf("Enter the elements of the array : \n");
    for(int i=0 ; i<n ; i++ )
    {
        scanf("%d",&a[i]);
    }
    printf("The Array : \n");
    for(int i=0 ; i<n ; i++ )
    {
        printf("%d\n",a[i]);
    }
    printf("---------------\n");
    for(int i=0 , j=n-1 ; i<j ; i++ , j--)
    {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    printf("The Reversed Array : \n");
    for(int i=0 ; i<n ; i++ )
    {
        printf("%d\n",a[i]);
    }
    return 0;
}