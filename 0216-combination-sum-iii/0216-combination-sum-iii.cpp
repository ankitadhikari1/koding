class Solution {
public:
    void func(int ind,int k , int n, vector<vector<int>>&ans,vector<int>&temp,int cnt){
        if(n==0 && cnt == k){
            ans.push_back(temp);
            return;
        }
        if(cnt>k)return;
        if(ind>9)return;
        temp.push_back(ind);
        func(ind+1,k,n-ind,ans,temp,cnt+1);
        temp.pop_back();
        func(ind+1,k,n,ans,temp,cnt);
    }




    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(1,k,n,ans,temp,0);
        return ans;
    }
};