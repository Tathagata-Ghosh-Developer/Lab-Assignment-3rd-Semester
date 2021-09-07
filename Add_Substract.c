/*Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/*Q3.Write a C program to add and subtract two integers having at least 10 digits each.*/

#include <stdio.h>

void add(int n1, int n2, int n, int num1[], int num2[]) 
{
	int sum[n + 1];
	int car = 0;
	for (int i = n - 1; i >= 0; i--) 
	{
		int digSum = num1[i] + num2[i] + car;
		car = digSum / 10;
		int dig = digSum % 10;
		sum[i + 1] = dig;
	}
	sum[0] = car;
	printf("Sum of the numbers is: \n");
	for (int i = 0; i <= n; i++) 
	{
		printf("%d", sum[i]);
	}
	printf("\n");
}

void sub(int n1, int n2, int n, int num1[], int num2[]) 
{
	int dif[n + 1];
	int car = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int digDif = num1[i] - num2[i] - car;
		if (digDif < 0)
		{
			car = 1;
			digDif += 10;
		}
		else 
		{
			car = 0;
		}
		dif[i + 1] = digDif;
	}
	dif[0] = car;

	for (int i = 1; i <= n; i++)
	{
		printf("%d", dif[i]);
	}
	printf("\n");
}

int main() 
{
	int n1;
	printf("--------------------------------------------\n");
	printf("Enter the number of digits in first number:\n");
	printf("--------------------------------------------\n");
	scanf("%d", &n1);
	int n2;
	printf("--------------------------------------------\n");
	printf("Enter the number of digits in second number:\n");
	printf("--------------------------------------------\n");
	scanf("%d", &n2);
	int n = n1 > n2 ? n1 : n2;
	int num1[n];
	int num2[n];

	printf("-------------------------------------------------------------\n");
	printf("Enter the first number, each digits being space separated:\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		if (i >= n - n1) {
			int x;
			scanf("%d", &x);
			num1[i] = x;
		}
		else
			num1[i] = 0;

	}
	printf("-------------------------------------------------------------\n");
	printf("Enter the second number, each digits being space separated:\n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < n; i++) 
	{
		if (i >= n - n2) 
		{
			int x;
			scanf("%d", &x);
			num2[i] = x;
		}
		else
			num2[i] = 0;
	}
	printf("----------------------------------\n");
	printf("Enter 1 to add and 2 to subtract:\n");
	printf("----------------------------------\n");
	int ch;
	scanf("%d", &ch);
	if (ch == 1) 
	{
		add(n1, n2, n, num1, num2);
	}
	else if (ch == 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (num1[i] > num2[i])
			{
				printf("-----------------------------\n");
				printf("Difference of the numbers is: \n");
				printf("-----------------------------\n");
				sub(n1, n2, n, num1, num2);
				break;
			}
			else if (num2[i] > num1[i])
			{
				printf("-");
				sub(n2, n1, n, num2, num1);
				break;
			}
		}
	}
	else
		printf("Enter a valid choice");
	return 0;
}