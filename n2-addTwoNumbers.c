#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * cur = head;
    int carry = 0; int sum = 0;
    while( l1 || l2){
        sum = 0;
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2 = l2->next;
        }
        sum += carry;
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = sum%10;new_node->next = NULL;
        cur->next = new_node; cur = cur->next;
        carry = sum / 10;
    }
    if(carry!=0){
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = carry;new_node->next = NULL;
        cur->next = new_node;
    }

    struct ListNode* result = head->next;
    free(head); // 释放头节点
    return result;
}