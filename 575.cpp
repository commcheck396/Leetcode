class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        int sum=1;
        sort(candy.begin(),candy.end());
        int tmp=candy[0];
        for(auto i:candy){
            if(tmp==i)continue;
            else{
                sum++;
                tmp=i;
            }
        }
        return min(candy.size()/2,sum);
    }
};