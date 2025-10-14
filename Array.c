// Array.c
// 简单的动态整型数组（append 实现）
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size; //size_t 是一种资料形态，他是不会有负数的int
    size_t capacity;
} IntArray;

/* 初始化动态数组，initial_capacity 为 0 时使用默认容量 4 */
IntArray array_init(size_t initial_capacity) {
    IntArray a;
    if (initial_capacity == 0) initial_capacity = 4;
    a.data = (int*)malloc(initial_capacity * sizeof(int));
    if (!a.data) {
        a.size = a.capacity = 0;
    } else {
        a.size = 0;
        a.capacity = initial_capacity;
    }
    return a;
}

/* 释放数组占用的内存 */
void array_free(IntArray *a) {
    if (a == NULL) return;
    free(a->data);
    a->data = NULL;
    a->size = a->capacity = 0;
}

/* 内部：扩容到至少 new_capacity，返回 0 成功，-1 失败 */
static int array_grow(IntArray *a, size_t new_capacity) {
    if (new_capacity <= a->capacity) return 0;
    int *p = (int*)realloc(a->data, new_capacity * sizeof(int));
    if (!p) return -1;
    a->data = p;
    a->capacity = new_capacity;
    return 0;
}

/* 在数组末尾追加一个元素，返回 0 成功，-1 内存分配失败 */
int array_append(IntArray *a, int value) {
    if (a == NULL) return -1;
    if (a->size + 1 > a->capacity) {
        size_t new_cap = a->capacity ? a->capacity * 2 : 4;
        if (array_grow(a, new_cap) != 0) return -1;
    }
    a->data[a->size++] = value;
    return 0;
}

/* 获取索引处元素（不做越界检查），可按需改为返回错误码 */
int array_get(const IntArray *a, size_t index) {
    return a->data[index];
}

/* 示例用法 */
int main(void) {
    IntArray a = array_init(0);

    for (int i = 0; i < 20; ++i) {
        if (array_append(&a, i * 10) != 0) {
            fprintf(stderr, "append failed\n");
            array_free(&a);
            return 1;
        }
    }

    for (size_t i = 0; i < a.size; ++i) {
        printf("a[%zu] = %d\n", i, array_get(&a, i));
    }
    printf("Size: %zu, Capacity: %zu\n", a.size, a.capacity);
    array_free(&a);
    return 0;
}