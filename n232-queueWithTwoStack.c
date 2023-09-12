#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10001
typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} MyQueue;
// data[front:rear) is valid

MyQueue* myQueueCreate() {
    MyQueue* new_queue = (MyQueue*)malloc(sizeof(MyQueue));
    new_queue->front = 0;
    new_queue->rear = 0;
    return new_queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->data[(obj->rear)] = x;
    obj->rear = (obj->rear+1) % MAX_SIZE;
}

int myQueuePop(MyQueue* obj) {
    int value = obj->data[obj->front];
    obj->front = (obj->front+1) % MAX_SIZE;
    return value;
}

int myQueuePeek(MyQueue* obj) {
    return obj->data[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->front == obj->rear;
}

void myQueueFree(MyQueue* obj) {
    if(!(obj==NULL))free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/