// class Solution {
// public:
//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//         int last_position=0,position=0,max_range=0,cur_position=0;
//         int radius=heaters[0]-houses[0];
//         max_range=radius+heaters[0];
//         for(int k=1;k<houses.size();k++){
//             if(houses[k]>=position-radius&&houses[k]<=position+radius)k++;
//             else{
//                 last_position=k;
//                 break;
//             }
//         }
//         int tmp;
//         for(int i=1;i<heaters.size();i++){
//             cur_position=last_position;
//             position=heaters[i];
//             for(;cur_position<houses.size();){
//                 if(houses[cur_position]<position-radius)cur_position++;
//                 // else if(houses[cur_position]>position+radius)
//                 else {
//                     // cur_position--;
//                     break;
//                 }
//             }
//             tmp=cur_position;
//             for(;cur_position>last_position+1;){
//                 while(houses[last_position]<=max_range)last_position++;
//                 while(houses[cur_position]>=position-radius)cur_position--;
//                 if(cur_position<=last_position+1)break;
//                 else{
//                     max_range++;
//                     radius++;
//                 }
//             }
//             for(int k=cur_position;k<houses.size();k++){
//                 if(houses[k]>=position-radius&&houses[k]<=position+radius)k++;
//                 else{
//                     last_position=k;
//                     break;
//                 }
//             }
//             // while(!(max_range>=houses[last_position]||position-radius<=houses[last_position])){
//             //     radius++;
//             //     max_range++;
//             // }
//             // for(int k=last_position+1;k<houses.size();k++){
//             //     if(houses[k]>=position-radius&&houses[k]<=position+radius)k++;
//             //     else{
//             //         last_position=k;
//             //         break;
//             //     }
//             // }
//         }
//         return radius;
//     }
// };


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        if(heaters.size()==1)radius=max(abs(houses[houses.size()-1]-heaters[0]),abs(heaters[0]-houses[0]));
        int cur_position=0,last_position=0,low=0,high=1;
        int last=houses[0];
        int k;
        for(k=0;k<heaters.size();){
            if(heaters[k]<houses[0])k++;
            else break;
        }
        int radius;
        if(k==0){
            radius=abs(houses[0]-heaters[0]);
            low=0;
            high=1;
        }
        else {
            radius=min(abs(heaters[k]-houses[0]),abs(heaters[k-1]-houses[0]));
            low=k-1;
            high=k;
        }
        // return radius;
        int i;
        if(heaters.size()==1)radius=max(abs(houses[houses.size()-1]-heaters[0]),abs(heaters[0]-houses[0]));
        for(i=1;i<houses.size();){
            if(houses[i]<=heaters[k])i++;
            else break;
        }
        for(;i<houses.size();i++){
            if(houses[i]==last)continue;
            else{
                last=houses[i];
            }
            while(!(houses[i]>=heaters[low]&&houses[i]<=heaters[high])){
                low=high;
                high++;
                if(high>=heaters.size()){
                    radius=max(radius,houses[houses.size()-1]-heaters[low]);
                    return radius;
                }
            }
            radius=max(radius,min(heaters[high]-houses[i],houses[i]-heaters[low]));
        }
        return radius;
    }
};