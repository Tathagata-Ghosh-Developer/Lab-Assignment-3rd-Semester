#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} LL;

LL *head = NULL;

void addNode(int val){
    LL *current;
    LL *new_node = (LL *)malloc(sizeof(LL));
    new_node->data = val;
    new_node->next = NULL;

    if(head == NULL || head->data >= new_node->data){
        new_node->next = head;
        head = new_node;
    }
    else{
        current = head;
        while(current->next != NULL && current->next->data < new_node->data){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int generateRand(int lower, int upper) {
    int randInt = (rand() % (upper - lower + 1)) + lower;
    return randInt;
}

int countLL = 6, countArr = 6;

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    double avgLL, avgArr;

    clock_t LL6Iteration = clock();
    printf("\n*** Linked List ***");
    srand(time(0));
    while(countLL){
        clock_t t = clock();

        head = (LL *)malloc(sizeof(LL));    
        for(int i=0; i<N; i++){
            int num = generateRand(0, 10000);
            addNode(num);
        }

        printf("\n------------------------------------\n");
        printf("First 10 elements for N = %d\n", N);
        printf("------------------------------------\n");

        LL *temp = head;
        int n = 10;
        while(n--){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
        countLL--;
        t = clock() - t;
        double time = ((double) t) / CLOCKS_PER_SEC;
        printf("    | Time taken : %f", time);
        avgLL += time;
    }
    printf("\n------------------------------------");
    LL6Iteration = clock() - LL6Iteration;
    double time_taken = ((double) LL6Iteration) / CLOCKS_PER_SEC;
    printf("\n\n=========================================================");
    printf("\nTime taken by [ Linked List ] for 6 iterations : %f\n", time_taken);
    printf("\nAverage time taken by [ Linked List ] : %f\n", avgLL/6);
    printf("=========================================================");


    clock_t Array6Iteration = clock();
    printf("\n\n*** Array ***");
    srand(time(0));
    while(countArr){
        clock_t t = clock();
        
        int arr[N];
        for(int i=0; i<N; i++){
            int num = generateRand(0, 10000);
            int j=0;
            while( arr[j] <= num && j<i )
                j++;
            int pos = i;
            while(pos > j){
                arr[pos] = arr[pos - 1];
                pos--;
            }
            arr[j] = num;
        }

        printf("\n------------------------------------\n");
        printf("First 10 elements for N = %d\n", N);
        printf("------------------------------------\n");
        for(int i=0; i<10; i++){
            printf("%d ", arr[i]);
        }
        countArr--;
        t = clock() - t;
        double time = ((double) t) / CLOCKS_PER_SEC;
        printf("    | Time taken : %f", time);
        avgArr += time;
    }
    printf("\n------------------------------------");
    Array6Iteration = clock() - Array6Iteration;
    double time_taken2 = ((double) Array6Iteration) / CLOCKS_PER_SEC;
    printf("\n\n=========================================================");
    printf("\nTime taken by [ Array ] for 6 iterations : %f\n", time_taken2);
    printf("\nAverage time taken by [ Array ] : %f\n", avgArr/6);
    printf("=========================================================\n");


    return 0;
}
