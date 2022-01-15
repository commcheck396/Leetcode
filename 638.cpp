int n;
class Solution {
public:
    int gift[n+2],giftprice[n+2];
    int judge(vector<int>& price, vector<vector<int>>& special){
        int tmp=0;
        for(int k=0;k<special.size();k++){
            for(int i=0;i<n;i++){
                tmp+=price[special[k][i]];
            }
            if(tmp<special[k][i])special[k][i]=INT_MAX;
        }
        return 0;
    }

    int translate(vector<int>& price, vector<vector<int>>& special){
        int tmp=0;
        for(int k=0;k<special.size();k++){
            for(int i=0;i<n;i++){
                tmp=tmp|(special[k][i]<<(i*4));
            }
            giftprice[k]=special[k][i];
        }
        return 0;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int dp[0xaaaaab];
        for(int i=0;i<n;i++){
            for(int k=1;k*)
        }
    }
};