class Solution {
public:

    bool check(string&s,int i , int j){
        if(i>=j)return true;
        if(s[i]==s[j]){
            return check(s,i+1,j-1);
        }
        return false;
    }


    string longestPalindrome(string s) {
        int maxString = -1;
        int maxSize = INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    if(j-i+1 > maxSize){
                        maxSize = j-i+1;
                        maxString = i;
                    }
                }
            }
        }
        return s.substr(maxString,maxSize);
    }
};