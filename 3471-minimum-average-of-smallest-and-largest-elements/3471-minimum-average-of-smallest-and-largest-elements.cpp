class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        double average = INT_MAX;
        while(i<j){
            double sum = nums[i] + nums[j];
            double avg = sum/2.0;
            if(avg<average){
                average = avg;
            }
            i++,j--;
        }
        return average;
    }
};