class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i,k,b,c;
        vector<string> ans;
        for(i=1;i<=n;i++){
            if(n%15==0)ans.push_back("FizzBuzz");
            else if(n%5==0)ans.push_back("Buzz");
            else if(n%3==0)ans.push_back("Fizz");
            else ans.push_back(to_string(n));
        }
        return ans;
    }
};