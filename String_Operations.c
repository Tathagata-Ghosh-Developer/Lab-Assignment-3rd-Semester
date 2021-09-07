/*Programming Laboratory Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
07/09/2021*/

/* Q2. Write a C program that uses functions to perform the following operations:
i) To insert a sub-string in to given main string from a given position.
ii) To delete n characters from a given position in a given string.*/

#include <stdio.h>
#include <string.h>

void addSubStr(char s[]) 
{
	char news[1000] = {'\0'};
	char sub[1000];
	printf("Enter the substring to insert: \n");
	gets(sub);

	printf("Enter the position from where you want to insert to insert: \n");
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) 
	{
		news[i] = s[i];
	}
	for (int i = k; i < k + strlen(sub); i++) 
	{
		news[i] = sub[i - k];
	}
	int i = k, j = k + strlen(sub);
	while (s[i] != '\0') 
	{
		news[j] = s[i];
		i++;
		j++;
	}
	printf("New string is: %s \n", news);
}

void deleteChars(char s[]) 
{
	printf("Enter number of characters to delete: ");
	int n;
	scanf("%d", &n);
	printf("Enter the position from which to delete: ");
	int k;
	scanf("%d", &k);

	char news[1000] = {'\0'};
	int i = 0, j = 0;
	while (s[i] != '\0') 
	{
		if (i == k) 
		{
			i += n;
		}
		news[j] = s[i];
		i++;
		j++;
	}
	printf("New string is: %s \n", news);
}

int main() 
{
	char s[1000];
	
	printf("Enter a string: \n");
	gets(s);
	
	printf("Enter 1: To insert a sub-string in to given main string from a given position \n");
	printf("Enter 2: To delete n characters from a given position in the given string \n");
	printf("Enter your choice: \n");
	
	int ch;
	scanf("%d", &ch);
	int a = getchar();
	
	if (ch == 1) 
	{
		addSubStr(s);
	}
	else if (ch == 2) 
	{
		deleteChars(s);
	}
	else 
	{
		printf("Enter a valid choice! \n");
	}
	return 0;
}