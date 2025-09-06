class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cnt = 0;
        int maxGain = 0;
        for(int i=0;i<gain.size();i++){
            cnt+=gain[i];
            maxGain = max(maxGain,cnt);
        }
        return maxGain;


        
    }
};