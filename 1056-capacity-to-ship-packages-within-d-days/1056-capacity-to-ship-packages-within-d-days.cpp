class Solution {
public:

    bool func(int mid,int days,vector<int>&weights){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid)return false;
            if(sum+weights[i]>mid){
                cnt++;
                sum=0;
                if(cnt>days)return false;
            }
            sum+=weights[i];
            
        }
        return true;
    }



    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(func(mid,days,weights)){
                ans = mid ;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};