/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast *low,*position;
        int i,b,c;
        for(i=0,position=head;i<k;i++){
            position=position->next;
        }
        fast=position;
        low=head;
        for(;fast->next;){
            fast=fast->next;
            low=low->next;
        }
        b=low->val;
        low->val=position->val;
        position->val=b;
        return head;
    }
};