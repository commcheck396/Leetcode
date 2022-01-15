class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i,k,b,c;
        int len1,len2;
        len1=nums1.size();
        len2=nums2.size();
        int start1=0,start2=0;
        int mid1,mid2,mid;
        int dis,flag;
        if((len1+len2)%2){
            dis=(len1+len2)/2;
            flag=1;
        }
        else {
            dis=(len1+len2)/2;
            flag=0;
        }
        for(;;){
            mid=dis/2;
            if(len1==0){
                if(flag){
                    return nums2[mid]+nums2[mid+1];
                }
                else {
                    return nums2[mid];
                }
            }
            else if(len2==0){
                if(flag){
                    return nums1[mid]+nums1[mid+1];
                }
                else {
                    return nums1[mid];
                }
            }
            else {
                mid1=(start1+mid)>=len1?len1-1:(start1+mid);
                mid2=(start2+mid)>=len2?len2-1:(start2+mid);
                if(nums1[mid1]>nums2[mid2]){
                    if(mid2==len2-1){
                        len2=0;
                    }
                    dis-=mid2;
                    start2=mid2;
                }
                else{
                    if(mid1==len1-1){
                        len1=0;
                    }
                    dis-=mid1;
                    start1=mid1;
                }
                if(dis==1){
                    if(flag){
                        if(start1+2<)
                            int ans=nums1[start1+1]+nums1[start1+2];
                            ans=min(ans,nums1[start1+1]+nums2[start2+1]);
                            ans=min(ans,nums2[start2+1]+nums2[start2+2]);
                        }
                        else return nums1[start1+1]>nums2[start2+1]?nums2[start2+1]:nums1[start1+1];
                }
            }
        }
        return 0;
    }
};