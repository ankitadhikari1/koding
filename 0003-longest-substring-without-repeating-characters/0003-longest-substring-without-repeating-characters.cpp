class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st;
        int left = 0;
        int ans =0;
        
        for(int right = 0;right<s.size();right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans,right-left+1);

        }

        return ans;
    }
};