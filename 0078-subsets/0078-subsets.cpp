class Solution {
public:
     void generateAllPowerSet(int ind, vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){
        if(ind == nums.size()){
            ans.push_back(temp);
            return ;
        }

        generateAllPowerSet(ind+1,temp,ans,nums);
        temp.push_back(nums[ind]);
        generateAllPowerSet(ind+1,temp,ans,nums);
        temp.pop_back();
    }


    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        generateAllPowerSet(0,temp,ans,nums);
        return ans;
    }
};