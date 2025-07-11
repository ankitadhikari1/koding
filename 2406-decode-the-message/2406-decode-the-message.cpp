class Solution {
public:
    string decodeMessage(string key, string arr) {
        unordered_map<char,char>mp;
      int n=key.size();
      int j=0;
      for(char ch:key){
        if(ch!=' '&&mp[ch]==0){
            mp[ch]=j+'a';
            j++;
        }
      }
      string str;
      for(char ch:arr){
        if(ch==' '){
            str+=' ';
        }else{
            str+=mp[ch];
        }
      }
      return str;
    }
};