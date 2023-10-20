

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode * c;
    struct ListNode * n;
    c = dummy;
    n = c->next;
    while(n){
        if(c->val == n->val){
            c->next = n->next;
            n = c->next;
        }else{
            c = c->next;
            n = n->next;
        }
    }
    return dummy->next;
}