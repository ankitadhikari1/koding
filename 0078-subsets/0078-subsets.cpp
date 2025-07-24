class Solution {
public:

    void func(int ind,vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[ind]);
        func(ind+1,ans,temp,nums);
        temp.pop_back();
        func(ind+1,ans,temp,nums);

    }



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,ans,temp,nums);
        return ans;
    }
};