class Solution {
public:

    void func(int n , string s, vector<string>&ans, int open, int close){
        if(open > n)return;
        if((open + close) == 2 * n && (open == close)){
            ans.push_back(s);
            return;
        }

       if(open < n){
        func(n,s+'(',ans,open+1,close);
       }
       if(open > close){
        func(n,s+')',ans,open,close+1);
       }
    }


    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int cnt = 0;
        string s = "";
        func(n,s,ans,0,0);
        return ans;
    }
};