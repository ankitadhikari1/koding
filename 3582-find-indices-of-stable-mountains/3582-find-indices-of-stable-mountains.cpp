class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int>ans;
        for (size_t i = 0; i < height.size() - 1; ++i) {
            int prv = height[i];
            if (prv > threshold) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};