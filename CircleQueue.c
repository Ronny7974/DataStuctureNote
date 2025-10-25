#include<stdio.h>
#include<stdlib.h>

typedef struct CircleQueue{
    int front;
    int rear;
    int size;
    int *data;
}CircleQueue, circleQueue; 

void initQueue(CircleQueue *q, int size){
    q = (CircleQueue*)malloc(sizeof(CircleQueue));
    if(!q){
        printf("malloc Fail error");
        return;
    }
    q -> front = 0;
    q -> rear = 0;
    q -> size = size;
    q -> data = (int*)malloc(sizeof(int)*size);
    if(!(q -> data)){
        printf("malloc Fail error");
        return;
    } 
}

void enqueue(CircleQueue* q, int a){
    if(q -> front == (q -> rear + 1) % q -> size){
        printf("queue is full");
        return;
    }
    q -> data[q -> rear] = a;
    q -> rear = (q -> rear + 1) % q -> size;
}

int dequeue(CircleQueue* q){
    if(q -> front == q -> rear){
        printf("queue is empty");
        return 0;
    }
    int t = q -> data[q -> front];
    q -> front = (q -> front + 1) % q -> size;
    return t;
}

int main(){
    // The original initQueue is buggy, so we initialize manually here.
    CircleQueue *cq = (CircleQueue*)malloc(sizeof(CircleQueue));
    if (!cq) {
        printf("malloc Fail error");
        return 1;
    }
    cq->front = 0;
    cq->rear = 0;
    cq->size = 5; // As per the original call
    cq->data = (int*)malloc(sizeof(int) * cq->size);
    if (!cq->data) {
        printf("malloc Fail error");
        free(cq);
        return 1;
    }

    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);

    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 10
    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 20

    // 此时队列中有元素 30, front=2, rear=3
    // 队列前面有两个空位，现在可以重新利用它们
    // Note: With the original logic, the queue can only hold 4 elements.
    enqueue(cq, 40);
    enqueue(cq, 50);
    enqueue(cq, 60); // The queue is now full.
    
    // 尝试再入队一个
    enqueue(cq, 70); // This will print "queue is full"

    printf("--- Dequeuing all elements ---\n");
    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 30
    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 40
    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 50
    printf("Dequeued: %d\n", dequeue(cq)); // 出队: 60
    
    // 尝试再出队一个
    printf("Dequeued: %d\n", dequeue(cq)); // 打印: queue is empty

    // 程序结束前，释放内存
    free(cq->data);
    free(cq);

    return 0;
}