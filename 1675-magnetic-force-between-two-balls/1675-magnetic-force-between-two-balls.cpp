class Solution {
public:

 int func(vector<int>&nums,int k , int dist){
        int last = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last>=dist){
              cnt++;
              last = nums[i];
            }
        }

        return cnt >= k; 
    }




    int maxDistance(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low + (high - low)/2;
            int flag = func(nums,k,mid);
            if(flag){
              low = mid + 1;
            }
            else{
              high = mid -1;
            }
        }


        return high;
    }
};