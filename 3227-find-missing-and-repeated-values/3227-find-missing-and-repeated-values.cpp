class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        long long n = nums.size() * nums.size();
        long long sum = 0;
        long long sumn = (n * (n+1))/2;;
        long long sqsum = 0;
        long long sqsumn = (n * (n+1) * (2*n+1))/6;

        

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                sum+=nums[i][j];
                sqsum += (long long)nums[i][j] * (long long)nums[i][j];
            }
        }

       
        long long first = sum - sumn;
        long long second = sqsum - sqsumn;

        second/=first;

        long long x = (first+second)/2;
        long long y = x - first;

        return {(int)x,(int)y};


    }
};