class Solution {
public:
    string originalDigits(string s) {
        // sort(s.begin(),s.end());
        string ans;
        unordered_map<char,int>mark;
        for(auto c:s){
            mark[c]++;
        }
        vector<int>sum(10,0);
        sum[0]=mark['z'];
        sum[2]=mark['w'];
        sum[8]=mark['g'];
        sum[6]=mark['x'];
        sum[3]=mark['t']-sum[2]-sum[8];
        sum[4]=mark['r']-sum[3]-sum[0];
        sum[7]=mark['s']-sum[6];
        sum[1]=mark['o']-sum[2]-sum[4]-sum[0];
        sum[5]=mark['v']-sum[7];
        sum[9]=mark['i']-sum[8]-sum[6]-sum[5];
        for(int i=0;i<10;i++){
            for(int k=0;k<sum[i];k++){
                ans.push_back('0'+i)
            }
        }
        return ans;
    }
};