/* Data Structure Lab Assignment 2021
Tathagata Ghosh --- 2020ITB065 ---- HY
01/10/2021 */

/*2. In road traffic maintenance we know the traffic signal is used. Depending on the
real time traffic a particular signal is made on/off for a few seconds. If we have
the traffic data available then write a program in C to manage the traffic signal.
Consider there is a 5 road connector and you have to provide the signal for each
of the roads. Generate the time for each traffic between 10 to 20 sec randomly
and provide the signal for each of the roads one by one.
If for any reason one road is to be blocked then block that road and provide the
signal for remaining roads as earlier*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <time.h>
#define roads 5

struct Queue
{
    int size, f, r, count;
    char *arr;
};

struct Queue *setQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->size = roads, q->count = 0;
    q->f = 0, q->r = -1;
    q->arr = (char *)malloc(q->size * sizeof(char));
    return q;
}

void enQueue(struct Queue *q, char val)
{
    if (q->count != q->size)
    {
        do
        {
            q->r = (q->r + 1) % q->size;
        } while (q->arr[q->r] == 'B');
        q->arr[q->r] = val;
        q->count++;
    }
}

char deQueueF(struct Queue *q)
{
    if (q->count)
    {
        int index;
        do
        {
            index = q->f++;
            q->f %= q->size;
        } while (q->arr[index] == 'B');
        q->count--;
    }
}

void deQueueR(struct Queue *q)
{
    if (q->count)
    {
        int index;
        do
        {
            index = q->r--;
            q->r = (q->r == -1) ? q->size - 1 : q->r;
        } while (q->arr[index] == 'B');
        q->count--;
    }
}

void display(struct Queue *q)
{
    printf("\nRoad:\t");
    for (int i = 0; i < q->size; i++)
    {
        printf("%d\t", i + 1);
    }
    printf("\nSignal:\t");
    for (int i = 0; i < q->size; i++)
    {
        switch (q->arr[i])
        {
        case 'R':
            printf("Red\t");
            break;
        case 'Y':
            printf("Yellow\t");
            break;
        case 'G':
            printf("Green\t");
            break;
        case 'B':
            printf("Block\t");
            break;
        }
    }
    printf("\n");
}

int main()
{
    struct Queue *q = setQueue();
    while (q->count != q->size)
    {
        enQueue(q, 'R');
    }

    int blockedPath;
    printf("To Block any road, enter Road No. (1<=n<=5), else enter 0: ");
    scanf("%d", &blockedPath);
    (blockedPath) ? q->arr[blockedPath - 1] = 'B' : 1;

    for (int i = 1; i; i++)
    {
        deQueueR(q);
        deQueueR(q);
        deQueueR(q);
        enQueue(q, 'R');
        enQueue(q, 'Y');
        enQueue(q, 'G');

        deQueueF(q);
        enQueue(q, 'Y');

        display(q);

        srand(time(NULL));
        int time = 10 + rand() % 11;
        sleep(time);
    }
    return 0;
}