class Solution {
public:
    string frequencySort(string s) {
        map<char , int>arr;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        sort(s.begin(),s.end(),[&](char a , char b){
            if(arr[a-'a']>arr[b-'a']){
                return true;
            }
            if(arr[a-'a']==arr[b-'a']){
                return a<b;
            }
            return false;
        });
        return s;
    }
};