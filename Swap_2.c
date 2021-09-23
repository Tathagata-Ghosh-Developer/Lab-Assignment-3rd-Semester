/*Programming Lab Assignment-3 23-09-2021 Tathagata Ghosh 2020ITB065*/

/*Q1) Write a program in C to demonstrate how to swap the values of two variables using a function. 
Write the function in two way.One using a pass by value and another using a pass by reference.*/

#include<stdio.h>

void swap( int *a , int *b )
{
    *a = *a + *b ;
    *b = *a - *b ;
    *a = *a - *b ;
    return;
}
void swap1(int a, int b)
{
    int t=a;
    a=b;
    b=t;
    printf("After swapping by call by value:\n");
    printf("a=%d\nb=%d\n",a,b);
    return;
}
int main()
{
    int a , b ;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &a , &b );
    int *aptr = &a ;
    int *bptr = &b ;
    printf("a=%d & b=%d before swapping.\n", *aptr , *bptr );
    int ch;
    do
    {
        printf("Enter your choice:\n 1.Swap (call by reference)\n 2.Swap (call by value)\n 3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:swap( aptr , bptr );
                printf("After swapping by call by reference:\n");
                printf("a=%d\nb=%d\n",*aptr,*bptr);
                break;
            case 2:swap1(a,b);
                break;
            case 3: break;
            default: printf("---Invalid Input---\n");
                break;
        }
    } while (ch!=3);
    return 0;
}