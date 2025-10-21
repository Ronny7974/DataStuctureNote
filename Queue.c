#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node, node;
typedef struct  Queue
{
    Node *front;
    Node *rear;
}Queue, queue;
void initQueue(Queue** q, int size){
    *q = (Queue*)malloc(sizeof(Queue));
    if(!*q){
        printf("malloc error\n");
        return;
    }
    (*q) -> front = NULL;
    (*q) -> rear = NULL;
}
void enqueue(Queue* q, int data){
    node *p = (node*)malloc(sizeof(node));
    if(!p){
        printf("malloc error\n");
        return;
    }
    p -> data = data;
    p -> next = NULL;
    if(q -> front == NULL){
        q -> front = p;
        q -> rear = p;
    }
    else{
        q -> rear -> next = p;
        q -> rear = p;
    }
}
int dequeue(Queue* q){
    if(q -> front == NULL){
        printf("queue is empty\n");
        return -1;
    }
    node *p = q -> front;
    int data = p -> data;
    q -> front = p -> next;
    free(p);
    if(q -> front == NULL){
        q -> rear = NULL;
    }
    return data;
}
int main(){
    Queue *q;
    initQueue(&q, 10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}