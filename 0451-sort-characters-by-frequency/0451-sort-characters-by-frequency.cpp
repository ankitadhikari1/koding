class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto &it : s){
            mp[it]++;
        }

        vector<pair<int,char>> v;
        for(auto& it : mp){
            v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());

        string ans = "";
        for(int i=0; i < v.size(); i++){
            int size = v[i].first;
            while(size--){
                ans += v[i].second;
            }
        }
        return ans;

    }
};