#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *nextLL;
} LL;

LL * createList(LL *head) {
    head = NULL;
    int t;
    printf("Enter number of nodes : ");
    scanf("%d", &t);
    while(t--){
        int val;
        printf("Enter value : ");
        scanf("%d", &val);
        LL *new_node = (LL *)malloc(sizeof(LL));
        new_node->data = val;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
        }
        else{
            LL *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    return head;
}

void displayLLofLL(LL *ptr){
    while(ptr->nextLL != NULL){
        LL *current = ptr;
        while(current->next != NULL){
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("%d", current->data);
        printf("\n|\n");
        ptr = ptr->nextLL;
    }
    LL *current = ptr;
    while(current->next != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
    printf("\n");
}

int main() {

    int n;
    printf("Enter number of list : ");
    scanf("%d", &n);
    
    LL *headList = (LL *)malloc(sizeof(LL));
    headList = NULL;
    for(int i=0; i<n; i++){
        if(headList == NULL){
            headList = createList(headList);
            headList->nextLL = NULL;
        } else{
            LL *list = (LL *)malloc(sizeof(LL));
            list = createList(list);
            list->nextLL = NULL;
            LL *current = headList;
            while(current->nextLL != NULL){
                current = current->nextLL;
            }
            list->nextLL = current->nextLL;
            current->nextLL = list;
        }
        
        printf("\n");
    }

    displayLLofLL(headList);

    printf("\n================================\n");
    printf("Convert LL of LL into Singly LL");
    printf("\n================================\n\n");
    
    LL *singlyLL = (LL *)malloc(sizeof(LL));
    singlyLL = NULL;
    while(headList != NULL){
        LL *current = headList;
        while(current != NULL){
            LL *newNode = (LL *)malloc(sizeof(LL));
            newNode->data = current->data;
            newNode->next = NULL;
            if(singlyLL == NULL){
                singlyLL = newNode;
            }
            else{
                LL *ptr = singlyLL;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
            current = current->next;
        }
        headList = headList->nextLL;
    }

    while(singlyLL != NULL){
        printf("%d ", singlyLL->data);
        singlyLL = singlyLL->next;
    }
    printf("\n");
}