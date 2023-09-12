#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define MAX_SIZE 10001


bool isPalindrome(struct ListNode* head){
    int l[MAX_SIZE]={0};
    int rear = -1;
    struct ListNode * cur = head;
    while(cur){
        l[++rear] = cur->val;
        cur = cur->next;
    }
    int front=0;
    while(front<rear){
        if(l[front++]!=l[rear--])return false;
    }
    return true;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main(){
    // 创建链表节点
    struct ListNode* node1 = createNode(1);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(2);
    struct ListNode* node4 = createNode(1);

    // 构建链表
    struct ListNode* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("%d",isPalindrome(node1)); 

    free(node1);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}