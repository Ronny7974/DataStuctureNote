#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack* stack_init(void){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(!stack){
        printf("Stack malloc error\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

void stack_push(Stack *stack, int a){
    Node *b = (Node*)malloc(sizeof(Node));
    if(!b){
        printf("Push malloc error\n");
        return;
    }
    b->data = a;
    b->next = stack->top;  // 新节点指向旧栈顶
    stack->top = b;        // 更新栈顶
}

int stack_pop(Stack *stack){
    int t = stack->top->data;
    Node *a = stack->top;
    stack->top = stack->top->next;
    free(a);
    return t;
} 

int main(){
    Stack *a = stack_init();
    if(!a) return 1;

    stack_push(a, 15);
    stack_push(a, 10);

    printf("%d\n", a->top->data);        // 输出 10
    printf("%d\n", a->top->next->data);  // 输出 15

    printf("%d\n", stack_pop(a));
    printf("%d\n", stack_pop(a));
    
    free(a);
    return 0;
}
