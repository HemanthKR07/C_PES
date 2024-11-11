/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* parse = malloc(sizeof(struct ListNode));
    struct ListNode* head = parse;
    while (list1!=NULL || list2!=NULL){
        if (list1==NULL){
            parse->val = list2->val;
            list2 = list2->next;
        }else if (list2==NULL){
            parse->val = list1->val;
            list1 = list1->next;
        }else if (list1->val > list2->val){
            parse->val = list2->val;
            list2 = list2->next;
        }else{
            parse->val = list1->val;
            list1 = list1->next;
        }
        parse->next=malloc(sizeof(struct ListNode));
        parse=parse->next;
    }
    return head;
}