#include<stdio.h>
#include<stdlib.h>
/*
Input: head = [1,2,3,4,5,6]
Output: [2,1,4,3,6,5]
*/

struct Node
{
    int val;
    struct Node *next;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *cur = head;
    while(cur != NULL)
    {
        printf("%d \n", cur->val);
        cur = cur->next;
    }
}

struct Node *swapPair(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = head;
    struct Node *prev = temp;
    
    while(prev->next && prev->next->next)
    {
        struct Node *first = prev->next;
        struct Node *second = prev->next->next;
        
        //swap 
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        
        //Move next Pair
        prev = first;
    }
    
    struct Node *newHead = temp->next;
    free(temp);
    
    return newHead;
}

int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    
    printf("original list -> \n");
    printList(head);
    
    head = swapPair(head);
    
    printf("\n swap list \n");
    printList(head);
    return 0;
}
