class Solution {
public:

    void func(int ind,vector<int>&nums,int k, vector<vector<int>>&ans,vector<int>&temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(ind == nums.size())return;
        
        if(k-nums[ind]>=0){
            temp.push_back(nums[ind]);
            func(ind+1,nums,k-nums[ind],ans,temp);
            temp.pop_back();
        }
        int i;
        for(i=ind+1;i<nums.size();i++){
            if(nums[i]!=nums[ind]){
                break;
            }
        }
        func(i,nums,k,ans,temp);
    }




    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,nums,k,ans,temp);
        return ans;
    
    }
};