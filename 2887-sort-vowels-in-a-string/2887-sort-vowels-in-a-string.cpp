class Solution {
public:
    string sortVowels(string s) {
        vector<pair<char,int>>arr;
        unordered_set<char>st = {'a','e','i','o','u','A','E','I','O','U'};
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                arr.push_back({s[i],i});
            }
        }
        sort(arr.begin(),arr.end());
        int k = 0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                s[i] = arr[k++].first;
            }
        }
        return s;

        
    }
};