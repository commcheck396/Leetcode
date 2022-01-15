/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int i,b,c;
        ListNode *POSITION,*p;
        POSITION=head;
        for(i=0;i<k;i++){
            if(POSITION!=NULL)continue;
            else break;
        }
        p=head;
        for(;;){
            if(POSITION==NULL)break;
            POSITION=POSITION->next;
            p=p->next;
        }
        return p;
    }
};