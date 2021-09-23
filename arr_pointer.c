/*Programming Lab Assignment-3 23-09-2021 Tathagata Ghosh 2020ITB065*/

/*Q2) Demonstrate using a C program how the pointer to an array and array of pointers work.*/

#include<stdio.h>
const int SIZE = 5;
int main()
{
    int *ptr;
    int b[5] = {10,20,30,40,50};
    ptr = &b;
    printf("Printing elements in an array using pointer to an array:\n");
    for (int i = 0; i < 5; i++)
    {
       printf("b[%d]=%d\n",i, *(ptr + i));
    }
    printf("Printing elements of an array using array of pointers:\n");
    int *a[5];
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = &b[i];
    }
    for (int i = 0; i < SIZE; i++) 
    {
        printf(" b[%d] = %d\n", i, *a[i]);
    }
    return 0;
}