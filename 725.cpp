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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int i,j,b,c,len,sum,num;
        vector<ListNode*> a(k,nullptr);
        ListNode *position,*POSITION;
        position=head;
        for(i=0;;i++,position=position->next){
            if(position!=nullptr)continue;
            else break;
        }
        len=i;
        // for(c=k;;c++){
        //     if((len-c)%k==0)break;
        // }
        // sum=(len-c)/k;
        int flag;
        // for(c=k;c>0;c--){
        //     if(len%c==0){
        //         flag=1;
        //         num=len/c;
        //         break;
        //     }
        //     if((len-1)%c==0){
        //         flag=0;
        //         num=(len-1)/c;
        //         break;
        //     }
        // }
        b=len/k;
        c=len%k;

        sum=c;
        position=head;
        POSITION=head;
        for(i=0;i<c;i++){
            position=head;
            POSITION=head;
            for(j=0;j<num+1;j++){
                position=position->next;
            }
            if(position){            
                head=position->next;
                position->next=nullptr;
                }
            a[i]=POSITION;
        }
        for(i=c;i<sum;i++){
            position=head;
            POSITION=head;
            for(j=0;j<num;j++){
                position=position->next;
            }
            if(position){            
                head=position->next;
                position->next=nullptr;
                }
            a[i]=POSITION;
        }
        return a;
    }

};

