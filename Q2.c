//Assignment - 7 - Programming Lab
/* Tathagata Ghosh - 2020ITB065 - HY*/

/*Q2.     Design a set of
functions (such as ADD, DIV, POWER (to do x^y), etc.) of your choice and store
them in an array of function pointers. Write a program that will use these
functions from the array, based on the user input. DO NOT USE
switch-case/if-else to solve this problem.*/

#include <stdio.h>

double ADD(double x, double y) 
{
	return x + y;
}

double DIV(double x, double y) 
{
	return x / y;
}

double POWER(double x, double y) 
{
	if (y == 0) 
	{
		return 1;
	}
	return x * POWER(x, y - 1);
}

double SUBTRACT(double x, double y) 
{
	return x - y;
}

double PRODUCT(double x, double y) 
{
	return x * y;
}

double (*ptr[5])(double x, double y);

int main() 
{
	ptr[0] = ADD;
	ptr[1] = DIV;
	ptr[2] = POWER;
	ptr[3] = SUBTRACT;
	ptr[4] = PRODUCT;
	printf("-------------------------------------------------------------\n");
	printf("Enter two numbers :\n");
	
	double x, y;
	scanf("%lf%lf", &x, &y);
	printf("-------------------------------------------------------------\n");
	printf("Enter 0 to Add %.2lf and %.2lf\n", x, y);
	printf("Enter 1 to Divide %.2lf by %.2lf\n", x, y);
	printf("Enter 2 to calculate %.2lf to the power %.2lf\n", x, y);
	printf("Enter 3 to subtract %.2lf from %.2lf\n", y, x);
	printf("Enter 4 to multiply %.2lf and %.2lf\n", x, y);

	int c;
	scanf("%d", &c);
	printf("-------------------------------------------------------------\n");
	double result = ptr[c](x, y);
	printf("Result = %.2lf\n", result);
	printf("-------------------------------------------------------------\n");

	return 0;
}