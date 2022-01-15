class TopVotedCandidate {
public:
    // vector<vector<int>>mark;
    unordered_map<int,int>mark;
    vector<int>winner;
    vector<int>time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_voted=0;
        time=times;
        int last_winner=-1;
        for(int i=0;i<persons.size();i++){
            mark[persons[i]]++;
            if(max_voted<=mark[persons[i]]){
                last_winner=persons[i];
                max_voted=mark[persons[i]];
                winner.push_back(persons[i]);
            }
            else {
                winner.push_back(last_winner);
            }
        }
    }
    
    int q(int t) {
        int position=lower_bound(time.begin(),time.end(),t)-time.begin();
        if(position==time.size())position=time.size()-1;
        return winner[position-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */