    class Solution {
    public:
        int numDecodings(string s) {
            int i,k,b,c,len;
            len=s.size();
            if(s[0]=='0')return 0;
            long long mod=1e9+7;
            long long dp[len+1][2];
            int last;
            for(i=0;i<len;i++){
                dp[i][0]=0;
                dp[i][1]=0;
            }
            if(s[0]=='*'){
                dp[0][0]=9;
                last=-1;
                }
            else {
                dp[0][0]=1;
                last=s[0]-'0';
            }
            for(i=1;i<len;i++){
                if(s[i]=='0'){
                    if(last==1||last==2){
                        dp[i][1]=dp[i-1][0];
                        dp[i][0]=0;
                    }
                    else if(last==-1){
                        
                        dp[i][1]=dp[i-1][0]/9*2;
                        dp[i][0]=0;
                    }
                    else{
                        return 0;
                    }
                    last=0;
                }
                else if(s[i]>='1'&&s[i]<='9'){
                    if(s[i]>='1'&&s[i]<='6'){
                        if(last==1||last==2){
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                            dp[i][1]=dp[i-1][0];
                        }
                        else if(last==-1){
                            dp[i][1]=dp[i-1][0]/9*2;
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                        }
                        else{
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                            dp[i][1]=0;
                        }
                        last=s[i]-'0';
                    }
                    else {
                        if(last==1){
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                            dp[i][1]=dp[i-1][0];
                        }
                        else if(last==-1){
                            dp[i][1]=dp[i-1][0]/9;
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                        }
                        else{
                            dp[i][0]=dp[i-1][0]+dp[i-1][1];
                            dp[i][1]=0;
                        }
                        last=s[i]-'0';
                    }
                }
                else if(s[i]=='*'){
                    if(last>=3||last==0){
                        dp[i][0]=dp[i-1][0]*9%(mod)+dp[i-1][1]*9%(mod);
                        dp[i][1]=0;
                    }
                    else if(last==1){
                        dp[i][0]=dp[i-1][0]*9%(mod)+dp[i-1][1]*9%(mod);
                        dp[i][1]=dp[i-1][0]*9%(mod);
                    }
                    else if(last==2){
                        dp[i][0]=dp[i-1][0]*9%(mod)+dp[i-1][1]*9%(mod);
                        dp[i][1]=dp[i-1][0]*6%(mod);
                    }
                    // else if(last==-1){
                    //     dp[i][0]=dp[i-1][0]*9+dp[i-1][1]*9;
                    //     dp[i][1]=dp[i-1][0]/9*9+dp[i-1][0]/9*6;
                    // }
                    last=-1;
                }
                dp[i][0]=dp[i][0]%(mod);
                dp[i][1]=dp[i][1]%(mod);
            }
            return (int)((dp[len-1][0]+dp[len-1][1])%mod);
        }
    };