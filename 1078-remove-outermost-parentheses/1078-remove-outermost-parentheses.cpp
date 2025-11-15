class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(cnt==0){
                    cnt++;
                }
                else{
                    ans+=s[i];
                    cnt++;
                }
            }
            else if(s[i]==')'){
                if(cnt==1){
                    cnt--;
                }
                else{
                    ans+=s[i];
                    cnt--;
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};