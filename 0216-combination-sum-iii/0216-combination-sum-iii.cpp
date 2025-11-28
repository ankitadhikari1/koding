class Solution {
public:

    void func(int ind , int k , int n  , vector<int>&temp ,vector<vector<int>>&ans,int sum ){
        if(ind > 9){
            if(sum == n && k == 0){
                ans.push_back(temp);
            }
            return ;
        }


        temp.push_back(ind);
        func(ind+1,k-1,n,temp,ans,sum+ind);
        temp.pop_back();
        func(ind+1,k,n,temp,ans,sum);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(1,k,n,temp,ans,0);
        return ans;
    }
};