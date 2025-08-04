class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxLen = 0;
        for(auto & it: st ){
            if(st.find(it-1)==st.end()){
                int currlen = 0;
                int currNum = it;
                while(st.find(currNum)!=st.end()){
                    currlen++;
                    currNum++;
                }
                maxLen = max(maxLen,currlen);
            }
        }

        return maxLen;

    }
};