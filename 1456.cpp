class Solution {
public:
    int maxVowels(string s, int k) {
        int i,b,c,len,ans=0,sum=0;
        len=s.size();
        //int dp[len+1];
        for(i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                sum++;
            }
        }
        ans=sum;
        for(i=k;i<len;i++){
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u'){
                sum--;
            }
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                sum++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};