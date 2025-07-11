class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
    }
};