class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int i,b;
        sort(arr.begin(),arr.end());
        while(arr.size()>k){
            arr.pop_back();
        }
        return arr;
    }
};