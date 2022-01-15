int times;
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        times=minutesToTest/minutesToDie;
        int updates=times+1;
        return ceil(log(buckets)/log(updates));
        
    }
};