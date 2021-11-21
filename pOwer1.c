/*Tathagata Ghosh --- 2020ITB065 --- HY*/

/*Programming Lab Assignments 
Q. Write a single function that will take two arguments a, b to find a^b. The argument a can be either integer or floating point number.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	float a,b,c,ans=1;

	if(argc!=3)
	{
		printf("please use \"prg_name value power \"\n");
		return -1;
	}
	
	a = (float)atoi(argv[1]);//can be int or float depending upon user
	b = (float)atoi(argv[2]);//from command line argument
    c = b;
	while(b--)
	{
		ans*=a;
	}

	printf("%f^%f = %f\n",a,c,ans);

	return 0;
}