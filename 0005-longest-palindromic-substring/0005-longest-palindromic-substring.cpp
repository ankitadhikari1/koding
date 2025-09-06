class Solution {
public:

    bool check(string&s,int i , int j,vector<vector<int>>&dp){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return check(s,i+1,j-1,dp);
        }
        return dp[i][j]=false;
    }


    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxString = -1;
        int maxSize = INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j,dp)){
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