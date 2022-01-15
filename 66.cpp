class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i++){
            if(digits[i]==9){
                continue;
            }
            else digits[i]++;
            return digits;
        }      
        digits.insert(digit.begin(),1);
        return digits;
    }
};