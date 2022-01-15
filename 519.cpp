int M,N;
class Solution {
public:
    unordered_map<int,int>mark;
    Solution(int m, int n) {
        M=m;
        N=n;
    }
    
    vector<int> flip() {
        int x=rand()%M;
        int y=rand()%N;
        while(!mark[(x+1)*1000+y+1]){
            x=rand()%M;
            y=rand()%N;
        }
        mark[(x+1)*1000+y+1]++;
        vector<int>ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
    
    void reset() {
        mark.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */