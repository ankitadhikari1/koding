class Solution {
public:

    bool func(vector<int>&nums,int days,int weight){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] > weight){
                cnt++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }

        return cnt <= days;
    }



    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high - low)/2;
            bool flag = func(nums,days,mid);
            if(flag){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};