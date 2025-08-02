class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n);
        int count=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==1) hash[i]=++count;
            else count=0;
        }int maxi=INT_MIN;
        maxi=*max_element(hash.begin(),hash.end());
        return maxi;
    }
};

