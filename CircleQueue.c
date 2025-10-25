#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, node;

typedef struct CircleQueue
{
    int size;
    Node *front;
    Node *rear;
}CircleQueue, circleQueue;

void initCircleQueue(CircleQueue **q, int size){
    *q = (CircleQueue*)malloc(sizeof(CircleQueue));
    if(!*q){
        printf("malloc error\n");
        return;
    }
    (*q) -> size = size;
    (*q) -> front = NULL;
    (*q) -> rear = NULL;
}

void enqueue(CircleQueue *q, int data){

    node *p = (node*)malloc(sizeof(node));
    if(!p){
        printf("malloc error\n");
        return;
    }
    p -> data = data;
    p -> next = NULL;
    if(q -> rear == NULL){

    }
}