class Solution {
public:

    bool check(vector<string>&temp,int r,int c){
        for(int i=r;i>=0;i--){
            if(temp[i][c]=='Q')return false;
        }

        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(temp[i][j]=='Q')return false;
        }

        for(int i=r,j=c;i>=0 && j>=0;i--,j++){
            if(temp[i][j]=='Q')return false;
        }

        return true;
        
    }


    void helper(vector<string>&temp,int r,vector<vector<string>>&ans , int n ){
        if(r==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(check(temp,r,i)==false)continue;
            temp[r][i]='Q';
            helper(temp,r+1,ans,n);
            temp[r][i]='.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string ab(n,'.'); // or kuch naam nahi yaad aya
        vector<string>temp(n,ab);
        helper(temp,0,ans,n);
        return ans;
    }
};