/* Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
21/09/2021 */

/*Q1. Write a function duplicateStack() that returns a new stack containing unique
elements in the same order as the given stack specified in the parameter.
Example:
Suppose the stack contains the elements : 10, 12, 10, 15, 20, 10, 15, 20, 25
So the duplicate stack should contain the elements: 10, 12, 15, 20, 25
Once this stack is created, display the contents of the stack and form this
stack revert back to the original stack contents.*/

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size, top, *arr;
};

struct Stack *setStack()
{
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    ptr->size = 100;
    ptr->top = -1;
    ptr->arr = (int *)malloc(ptr->size * sizeof(int));
    return ptr;
}

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! 101");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

void display(struct Stack *ptr)
{
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("%d\t", ptr->arr[i]);
    }
    printf("\n");
}

int *container, length;

struct Stack *duplicateStack(struct Stack *ptr)
{
    struct Stack *new = setStack();
    length = ptr->top + 1;
    int arr[length];
    container = (int *)malloc(length * sizeof(int));

    for (int index = length - 1; !isEmpty(ptr); index--)
    {
        arr[index] = pop(ptr);
    }

    for (int index = 0; index < length; index++)
    {
        int var = 1;
        for (int i = 0; i <= new->top; i++)
        {
            if (arr[i] == arr[index])
            {
                container[index] = i;
                var = 0;
                break;
            }
        }
        if (var)
        {
            push(new, arr[index]);
            container[index] = new->top;
            arr[new->top] = arr[index];
        }
    }
    return new;
}

struct Stack *revertBack(struct Stack *ptr)
{
    struct Stack *reverted = setStack();
    int newlength = ptr->top + 1;
    int arr[newlength];

    for (int index = newlength - 1; !isEmpty(ptr); index--)
    {
        arr[index] = pop(ptr);
    }

    for (int index = 0; index < length; index++)
    {
        push(reverted, arr[container[index]]);
    }
    return reverted;
}

int main()
{
    struct Stack *originalStack = setStack();
    int contentNum, content;

    printf("Enter the number of elements: ");
    scanf("%d", &contentNum);
    printf("\nEnter the element:\n");
    for (int i = 0; i < contentNum; i++)
    {
        printf("Element %d: ",i+1);
        scanf("%d", &content);
        push(originalStack, content);
    }
    printf("\n");

    printf("Original Stack:\n");
    display(originalStack);

    struct Stack *newStack = duplicateStack(originalStack);

    printf("New Stack:\n");
    display(newStack);

    struct Stack *revertedStack = revertBack(newStack);

    printf("Reverted Stack:\n");
    display(revertedStack);

    return 0;
}