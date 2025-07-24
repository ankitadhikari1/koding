class Solution {
public:

    void func(int ind,string s,vector<string>&ans, int n , int open,int close){
        if(open>n)return;
        if((open + close) == 2 * n && open == close ){
            ans.push_back(s);
            return;
        }
        if(open<n)
        func(ind+1,s+'(',ans,n,open+1,close);
        if(open>close){
            func(ind+1,s+')',ans,n,open,close+1);
        }


    }



    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(1,"",ans,n,0,0);
        return ans;
    }
};