/* Programming Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
01/10/2021 */

/*
I hope you have learned how a structure in C can be defined and also accessing the members of the structure using a variable. 
Now use pointer to a structure to access the members of that structure. Write a program in C to demonstrate this.*/
#include <stdio.h>
#include <string.h>


typedef struct farmer
{
    char name[30];
    char crop[30];
    int stock;
} frmr;

int main()
{
    printf("Enter number of farmers to tabulate information for: ");
    int n, i; 
    scanf("%d", &n);
    frmr f[n];
    printf("\nEnter the names of the farmer\n");
    for(i=0; i<n; i++)
    {
        printf("Enter name of Farmer %d\n", i+1);
        scanf("%s", &f[i].name);
    }
    printf("\nEnter the name of the crop grown by farmer respectively\n");
    for(i=0; i<n; i++)
    {
        printf("Enter crop name of Farmer %d\n" ,i+1);
        scanf("%s", &f[i].crop);
    }
    printf("\nEnter the amout of stock available of crop in kg\n");
    for(i=0; i<n; i++)
    {
         printf("Enter crop name of Farmer %d\n", i+1);
        scanf("%d", &f[i].stock);
    }
    printf("\n\nHere are the details of Farmers\n\n");
    printf("\nNAME\tCROP GROWN\tSTOCK\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t%s\t\t%d\t", f[i].name, f[i].crop, f[i].stock);
        printf("\n");
    }
    return 0;
}