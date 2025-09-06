class Solution {
public:
    string sortSentence(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                cnt++;
            }
        }

        vector<string>arr(cnt+1);
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                arr[(s[i]-'0')-1] = temp;
                temp = "";
            }
            else if(s[i]==' ')continue;
            else temp+=s[i];
        }

        string ans = "";
        for(auto &it : arr){
            ans+=it;
            ans+=' ';
        }
        return ans.substr(0,ans.size()-1);
    }
};