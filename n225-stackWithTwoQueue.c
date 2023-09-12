#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10001

// data[0,top] is valid
typedef struct {
    int top;
    int data[MAX_SIZE];
} MyStack;


MyStack* myStackCreate() {
    MyStack* new_stack = (MyStack*)malloc(sizeof(MyStack));
    new_stack->top=-1;
    return new_stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->data[++(obj->top)] = x;
}

int myStackPop(MyStack* obj) {
    return obj->data[(obj->top)--];
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    return obj->top==-1?true:false;
}

void myStackFree(MyStack* obj) {
    if(obj!=NULL)free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/