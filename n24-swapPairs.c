#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * prehead = (struct ListNode *)malloc(sizeof(struct ListNode));
    prehead->next = head; prehead->val = 0;
    struct ListNode * cur = prehead;
    while(cur->next&&cur->next->next){
        // 0->1->2->3
        // 0->1->3 2->3
        // 0->2->3 1->3
        // 0->2->1->3
        struct ListNode * temp1 = cur->next,*temp2 = cur->next->next;
        cur->next = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;
        cur = cur->next->next;
    }
    return prehead->next;
}