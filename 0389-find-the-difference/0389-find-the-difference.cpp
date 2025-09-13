class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto &it : t){
            mp[it]++;
        }
         for(auto &it : s){
            mp[it]--;
        }

        for(auto & it : mp){
            if(it.second == 1)return it.first;
        }

        return '@';
    }
};