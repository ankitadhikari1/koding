class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size()-1;
        int windowSum = 0;
        for(int i=0;i<k;i++){
            windowSum+=cardPoints[i];
        }
        int maxSum = windowSum;
        int i = 0;
        while(i<k){
            windowSum -= cardPoints[k-1-i];
            windowSum += cardPoints[n-i];
            maxSum = max(maxSum,windowSum);
            i++;
        }
        return maxSum;
    }
};