class Solution {
public:

    void func(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }


        temp.push_back(nums[ind]);
        func(ind+1,nums,ans,temp);
        temp.pop_back();

        int j ;
        for(j = ind;j<nums.size();j++){
            if(nums[j]!=nums[ind]){
                break;
            }
        }

        func(j,nums,ans,temp);

    }




    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,nums,ans,temp);
        return ans;
    }
};