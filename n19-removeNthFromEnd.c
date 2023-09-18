#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
   struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int total = 0;
    struct ListNode * cur = head;
    while(cur){cur=cur->next;total++;}
    if(total==0)return head;
    int m = total - n + 1; // 0,1,2,3 ...
    struct ListNode * beforehead = (struct ListNode *)malloc(sizeof(struct ListNode));
    beforehead->val = 0;
    beforehead->next = head;

    cur = beforehead;
    while(m--){
        if(m==0){
            cur->next = cur->next->next;
            break;
        }
        cur = cur->next;
    }

    return beforehead->next;
}


int main(){
    struct ListNode* node1 = createNode(1);
    struct ListNode* node2 = createNode(2);
    struct ListNode* node3 = createNode(3);
    struct ListNode* node4 = createNode(4);
    struct ListNode* node5 = createNode(5);

    // 构建链表
    struct ListNode* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    removeNthFromEnd(head,2);

    return 0;
}