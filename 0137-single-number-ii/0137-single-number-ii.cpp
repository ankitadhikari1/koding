class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &it:mp){
            if((it.second)%3!=0)return it.first;
        }
        return -1;
    }
};