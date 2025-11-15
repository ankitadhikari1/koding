class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = INT_MAX;
        for(auto & it : tasks){
            minTime = min(minTime, it[0]+it[1]);
        }
        return minTime;
    }
};