#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node, node;

typedef struct DoubleNode{
    int data;
    struct DoubleNode *prev;
    struct DoubleNode *next;
}DoubleNode, doubleNode;

typedef struct Queue
{
    int size;
    int count;
    Node *front;
    Node *rear;
}Queue, queue;

void initQueue(Queue **q, int size){
    *q = (Queue*)malloc(sizeof(Queue));
    if(!*q){
        printf("malloc error\n");
        return;
    }
    (*q) -> count = 0;
    (*q) -> size = size;
    (*q) -> front = NULL;
    (*q) -> rear = NULL;
}
void enqueue(Queue *q, int data){
    if(q -> size <= q -> count){
        printf("queue is full\n");
        return;
    }
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p){
        printf("malloc error\n");
        return;
    }
    p -> data = data;
    p -> next = NULL;
    if(q -> rear == NULL){
        q -> front = p;
        q -> rear = p;
    }
    else{
        q -> rear -> next = p;
        q -> rear = p;
    }
    q -> count++;
}

int dequeue(Queue *q){
    if(q -> count == 0){
        printf("queue is empty\n");
        return 0;
    }
    Node *p = q -> front;
    q -> front = q -> front -> next;
    int t = p -> data;
    q -> count--;
    if(q -> front == NULL){
        q -> rear = NULL;
    }
    free(p);
    return t;
}

int main(){
    Queue *q;
    initQueue(&q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}