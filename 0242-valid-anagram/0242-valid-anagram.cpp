class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;

        vector<int>hash(26,0);
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;
        }

        for(auto &it : hash){
            if(it!=0)return false;
        }

        return true;
    }
};