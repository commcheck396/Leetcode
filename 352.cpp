// int len;
// class SummaryRanges {
// public:
//     // int mark[100005];
//     //set<int>a;

//     vector<int>a;
//     SummaryRanges() {   
//         len=0;
//     }
    
//     void addNum(int val) {
//         int flag=1;
//         int i;
//         for(i=0;i<len;i++)if(a[i]==val){
//             flag=0;
//             break;
//         }
//         if(flag){
//             a.push_back(val);
//             sort(a.begin(),a.end());
//             len++;
//         }
//     }
    
//     vector<vector<int>> getIntervals() {
//         int i,k,b,c;
//         int start,end;
//         vector<vector<int>>ans;
//         if(a.empty())return ans;
//         else {
//             start=a[0];
//             end=a[0];
//         }
//         for(i=1;i<len;i++){
//             if(a[i]!=end+1){
//                 ans.push_back({start,a[i-1]});
//                 start=a[i];
//                 end=a[i];
//             }
//             else {
//                 end=a[i];
//                 continue;
//             }
//         }
//         ans.push_back({start,a[i-1]});
//         return ans;
//     }
// };

// /**
//  * Your SummaryRanges object will be instantiated and called as such:
//  * SummaryRanges* obj = new SummaryRanges();
//  * obj->addNum(val);
//  * vector<vector<int>> param_2 = obj->getIntervals();
//  */ 

class SummaryRanges {
public:
    // int mark[100005];
    set<int>a;
    // vector<int>a;
    SummaryRanges() {   
    }
    
    void addNum(int val) {
        a.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        int i,k,b,c;
        set<int>::iterator start,end;
        vector<vector<int>>ans;
        if(a.empty())return ans;
        else {
            start=a.begin();
            end=a.begin();
        }
        set<int>::iterator tmp=a.begin();
        for(;tmp!=a.end();tmp++){
            if(*tmp>*end+1){
                ans.push_back({*start,*end});
                start=tmp;
                end=tmp;
            }
            else {
                end=tmp;
                continue;
            }
        }
        ans.push_back({*start,*end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */ 