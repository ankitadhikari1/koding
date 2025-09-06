class Solution {
public:
    
    char shift(char c, int x){
        return c+x;
    }

    string replaceDigits(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                ans += s[i];
            }
            else if(isdigit(s[i])){
                int f = s[i] - '0';
                ans += shift(s[i-1],f);
            }
        }
        return ans;
    }
};