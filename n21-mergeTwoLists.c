#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode * beforehead = (struct ListNode*)malloc(sizeof(struct ListNode)); beforehead->next = NULL;beforehead->val=0;
    struct ListNode * cur1 = list1, * cur2 = list2,* cur = beforehead;
    while(cur1||cur2){
        if(!cur1){
            cur->next = cur2;
            cur = cur->next;
            cur2 = cur2->next;
            continue;
        }
        if(!cur2){
            cur->next = cur1;
            cur = cur->next;
            cur1 = cur1->next;
            continue;
        }
        if(cur1->val<cur2->val){
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }else{
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
    }
    cur->next = NULL;

    return beforehead->next;
}