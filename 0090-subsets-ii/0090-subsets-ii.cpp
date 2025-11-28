class Solution {
public:

    void func(int ind , vector<int>&nums ,vector<int>&temp , vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        func(ind+1,nums,temp,ans);
        temp.pop_back();

        int i;
        for(i=ind+1;i<nums.size();i++){
            if(nums[ind]!=nums[i]){
                break;
            }
        }

        func(i,nums,temp,ans);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,nums,temp,ans);
        return ans;
    }
};