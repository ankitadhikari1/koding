class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        vector<int>result;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]) count++;
            if(count==1){
                 result.push_back(nums[i]);
                 count=0;
        }
        }
        return result;      
    }
};