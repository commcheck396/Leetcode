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
    vector<int> nextLargerNodes(ListNode* head) {
        int i,k,b,c,len=0;
        vector<int>a;
        ListNode *position=head;
        for(i=0;position!=nullptr;i++,position=position->next){
            a.push_back(position->val);
        }
        stack<int>mark;
        vector<int>ans(a.size(),0);
        len=a.size();
        for(i=0;i<len;i++){
            while(!mark.empty()&&a[i]>a[mark.top()]){
                ans[mark.top()]=a[i];
                mark.pop();
            }
            mark.push_back(i);
        }
        return ans;
        // stack.push_back();
        // i=0;
        // for(position=position->next;position!=nullptr;position=position->next){
        //     while(!mark.empty()&&position->val>mark.top()){
        //         ans[i+mark.size()-1]=position->val;
        //         i++;
        //         mark.pop();
        //     }
        // }
    }
};