class Solution {
public:

    bool func(vector<int>&nums,int k , int dist){
        int last = nums[0];
        int cnt = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last>=dist){
                cnt++;
                last = nums[i];
            }
        }
        return cnt>=k;
    }



    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = *max_element(position.begin(),position.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            bool flag = func(position,m,mid);
            if(flag){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};