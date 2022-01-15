class Solution {
public:
    int nextGreaterElement(int n) {
        //string num=to_string(n);
        vector<int>num;
        for(;n!=0;n/=10){
            if(n==0)break;
            num.push_back(n%10);
        }
        reverse(num.begin(),num.end());
        // return num.size();
        int len=num.size();
        if(len<2)return -1;
        int position,min_;
        int mark[10];
        memset(mark,0,sizeof(mark));
        int flag=0;
        mark[num[len-1]]++;
        for(int i=len-2;i>=0;i--){
            mark[num[i]]++;
            for(int k=num[i]+1;k<=9;k++){
                if(mark[k]){
                    flag=1;
                    position=i;
                    // min_=k;
                    num[i]=k;
                    mark[k]--;
                    break;
                }
            }
            if(flag){
                for(int k=position+1;k<len;k++){
                    for(int j=0;j<=9;j++){
                        if(mark[j]){
                            num[k]=j;
                            mark[j]--;
                            break;
                        }
                    }
                }
            }
        }
        if(flag==0)return -1;
        else {
            int ans=0,times=1;
            for(int i=len-1;i>=0;i--){
                ans+=times*num[i];
                times*=10;
            }
            return  ans;
        }
        return -1;
        // for(int i=len-2;i>0;i--){
        //     min_=num[i];
        //     position=-1;
        //     for(int k=len-1;k>i;k--){
        //         if(min_>num[k]){
        //             position=k;
        //             min_=num[k];
        //         }
        //     }
        //     if(position!=-1){
        //         int tmp=num[i];
        //         num[i]=min_;
        //         num[position]=tmp;
        //         flag=1;
        //         break;
        //     }
        // }
        // if(flag==0){
        //     min_=num[0];
        //     position=-1;
        //     for(int k=len-1;k>0;k--){
        //         if(min_>num[k]&&num[k]!=0){
        //             position=k;
        //             min_=num[k];
        //         }
        //     }
        //     if(position!=-1){
        //         int tmp=num[0];
        //         num[0]=min_;
        //         num[position]=tmp;
        //         flag=1;
        //         // break;
        //     }
        // }
        // if(flag==0)return -1;
        // else {
        //     int ans=0,times=1;
        //     for(int i=len-1;i>=0;i--){
        //         ans+=times*num[i];
        //         times*=10;
        //     }
        //     return  ans;
        // }
        // return -1;
    }
};