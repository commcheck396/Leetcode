    class Solution {
    public:
        static bool cmp(vector<int> a,vector<int> b){
            return a[0]<b[0];
        }

        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int i,j,b,c,len,cur;
            len=profits.size();
            //int a[len+1][2];
            vector<pair<int, int>> a;
        for(i = 0; i < len; i ++) {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());
            priority_queue<int>p;
            i=0;
            while(k){
                for(;i<len&&w>=a[i].first;i++){
                    p.push(a[i].second);
                }
                if(p.empty())return w;
                w+=p.top();
                p.pop();
                k--;
            }
            return w;
        }
    };