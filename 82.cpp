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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode *fast=head,*slow=head,*position=head;
            int i,k,b,c;
            if(head==nullptr||head->next==nullptr)return head;
            c=head->val;
            fast=head->next;
            if(head->next->val==c)for(;;){
                if(fast->val!=c){
                    if(fast->next==nullptr){
                        position=fast;
                        break;
                    }
                    if(fast->val!=fast->next->val){
                        position=fast;
                        //position->next=nullptr;
                        break;
                    }
                    else{
                        c=fast->val;
                        fast=fast->next;
                    }
                }
                else {
                    fast=fast->next;
                    if(fast==nullptr)return nullptr;
                    continue;
                }
            }
            else position=head;
            slow=position;
            fast=position->next;
            if(fast==nullptr)return position;
            c=position->val;
            position->next=nullptr;
            for(;;){
                if(fast->val==c){
                    fast=fast->next;
                    if(fast==nullptr)break;
                    continue;
                }
                else {
                    if(fast->next==nullptr){
                        slow->next=fast;
                        break;
                    }
                    if(fast->val!=fast->next->val){
                        slow->next=fast;
                        c=fast->val;
                        slow=slow->next;
                        fast=fast->next;
                        slow->next=nullptr;
                    }
                    else{
                        c=fast->val;
                        fast=fast->next;
                    }
                }
            }
            return position;
        }
    };