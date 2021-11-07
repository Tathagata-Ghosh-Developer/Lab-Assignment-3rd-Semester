//Tathagata Ghosh - 2020ITB065 - HY - DSA Assignment 7  

/*Q1. Write a program to categorize the words having the same length with their frequency of
occurring in a given text. The list should display the frequency of each word corresponding
to a specific length taken as an input. Use a linked list to implement.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char s[20];
    int strlength;
    int freq;
    struct node *next;
};

struct node *head;
struct node *newnode;

void insert(char s1[20])
{
	struct node *temp;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));	
	temp=(struct node *)malloc(sizeof(struct node));
	strcpy(temp->s,s1);
	temp->freq=1;
	temp->strlength=strlen(s1);
	int flag=0,mark=0;
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        t=head;
        while(t!=NULL)
        {
            if(strcmp(s1,t->s)==0)
            {
                flag=1;
                t->freq ++;
                break;
                }
            t=t->next;	
        }
        if(flag==0)
        {
            if(head->strlength >= strlen(s1))
                {
                    temp->next=head;
                    head=temp;
                    mark=1;
                }
            else
            {
                t=head;
                while(t->next!=NULL)
                {
                    if(t->next->strlength >= strlen(s1))
                    {	
                        temp->next=t->next;
                        t->next=temp;
                        mark=1;
                        break;
                    }
                    t=t->next;
                }
                }
            if(mark==0)
            t->next=temp;	  
        }
    }
}

void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\n");
		puts(temp->s);
		printf("Frequency: %d",temp->freq);
		temp=temp->next;
	}
}
int main()
{
	head=NULL;
    char c[500];
    printf("\n Enter a string:");
    gets(c);
    int j=0;
    while(c[j]!='\0')
    {
        int k=0;
        char s1[20];
        for(;c[j]!=' ' && c[j]!='\0';j++)
           {
               s1[k]=c[j];
               k++;
           }
        s1[k]='\0';
        insert(s1); 
        if(c[j]=='\0')
           break;
        j++;   
   }
   display(); 
}