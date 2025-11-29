class Solution {
public:

    void func(int ind , vector<int>&nums , vector<int>&temp, vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        func(ind+1,nums,temp,ans);
        temp.push_back(nums[ind]);
        func(ind+1,nums,temp,ans);
        temp.pop_back();
        

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,nums,temp,ans);
        return ans;
    }
};