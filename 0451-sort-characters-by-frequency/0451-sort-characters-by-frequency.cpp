class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &it : s){
            mp[it]++;
        }
        vector<pair<int,char>>buff;
        for(auto &it : mp){
            buff.push_back({it.second,it.first});
        }

        sort(buff.begin(),buff.end(),[](pair<int,char>&a,pair<int,char>&b){
            if(a.first<b.first)return false;
            if(b.first<a.first)return true;
            return a.second<b.second;
        });

        string ans = "";

        for(auto & it : buff){
            int freq = it.first;
            int ch = it.second;
            ans.append(freq,ch);
        }


        return ans;
    }
};