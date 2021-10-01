/* Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
01/10/2021 */

/*1. The priority queue will be a collection of strings. Lexicographically smaller
strings should be considered higher priority than lexicographically larger
ones. For example, "ping" is higher priority than "pong", regardless of
insertion order.
Design the following functions:
i) enqueue is used to insert a new element to the priority queue.
ii) extractMin returns the value of highest priority (i.e., lexicographically smallest)
element in the queue and removes it.
iii) merge unifies the queues and returns their union as a new queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int size, f, r;
    char **arr;
};

struct Queue *setQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->f = q->r = -1;
    q->size = 10;
    q->arr = (char **)malloc(q->size * sizeof(char *));
    for (int i = 0; i < q->size; i++)
    {
        q->arr[i] = (char *)malloc(100 * sizeof(char));
    }
    return q;
}

void display(struct Queue *q)
{
    for (int i = 0; i <= q->r; i++)
    {
        printf("%s\n", q->arr[i]);
    }
}

void enQueue(struct Queue *q, char *string)
{
    if (q->r == q->size - 1)
        printf("This Queue is full\n");
    else
    {
        q->r++;
        strcpy(q->arr[q->r], string);

        char temp[100];
        for (int j = q->r - 1; j > -1 && strcmp(q->arr[j], string) == 1; j--)
        {
            strcpy(temp, q->arr[j]);
            strcpy(q->arr[j], q->arr[j + 1]);
            strcpy(q->arr[j + 1], temp);
        }

        printf("'%s' is successfully enQueued.\n", string);
    }
}

char *extractMin(struct Queue *q)
{
    char *a = (char *)malloc(100 * sizeof(char));
    strcpy(a, " - X - ");

    if (q->f == q->r)
        printf("This Queue is empty\n");
    else
    {
        q->f++;
        strcpy(a, q->arr[q->f]);
    }
    return a;
}

struct Queue *merge(struct Queue *q)
{
    struct Queue *new = setQueue();
    while (q->f != q->r)
    {
        strcpy(new->arr[++new->r], extractMin(q));
    }
    return new;
}

int main()
{
    struct Queue *strings = setQueue();
    int numOfWords;
    char word[100];

    printf("Enter the number of strings or words (0<s<10) you want to enQueue: ");
    scanf("%d", &numOfWords);
    printf("\nEnter the words:\n");
    for (int i = 0; i < numOfWords; i++)
    {
        printf("Word %d: ", i + 1);
        scanf("%s", word);
        enQueue(strings, word);
    }

    struct Queue *newStrings = merge(strings);

    free(strings);

    printf("\nDisplaying new lexicographically sorted Queue:\n");
    display(newStrings);

    return 0;
}