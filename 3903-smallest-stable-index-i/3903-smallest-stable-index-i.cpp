class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxElement(n),minElement(n);
        maxElement[0] = nums[0];
        for(int i=1;i<n;i++){
            maxElement[i] = max(nums[i],maxElement[i-1]);
        }
        minElement[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            minElement[i] = min(nums[i],minElement[i+1]);
        }

        for(int i=0;i<n;i++){
            if(maxElement[i]-minElement[i]<=k){
                return i;
            }
        }

        return -1;
    }
};