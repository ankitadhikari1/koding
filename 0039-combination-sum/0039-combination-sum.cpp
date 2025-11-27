class Solution {
public:

    void func(int ind , vector<int>&candidates , int target , vector<int>&temp, vector<vector<int>>&ans){
        if(ind == candidates.size()){
            if(target==0)
            ans.push_back(temp);
            return;
        }

        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            func(ind,candidates,target-candidates[ind],temp,ans);
            temp.pop_back();
        }

        func(ind+1,candidates,target,temp,ans);


    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,candidates , target,temp,ans);
        return ans;
    }
};