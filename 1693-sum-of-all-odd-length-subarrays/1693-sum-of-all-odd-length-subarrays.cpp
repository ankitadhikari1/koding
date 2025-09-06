class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            long long left = i + 1;        
            long long right = n - i;      
            long long totalPairs = left * right;
            long long oddCount = (totalPairs + 1) / 2; 
            ans += oddCount * arr[i];
        }
        return (int)ans;
    }
};