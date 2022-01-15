class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i,k,b,c,len;
        len=arr.size();
        int high,low,mid;
        high=len-1;
        low=0;
        mid=(high+low)/2;
        for(;mid>0&&mid<len-2;){
            if(arr[mid]>arr[mid-1]&&arr[mid+1]>arr[mid]){
                low=mid+1;
                mid=(high+low)/2;
            }
            else if(arr[mid]<arr[mid-1]&&arr[mid+1]<arr[mid]){
                high=mid-1;
                mid=(high+low)/2;
            }
            else return mid;
        }
        return mid;
    }
};