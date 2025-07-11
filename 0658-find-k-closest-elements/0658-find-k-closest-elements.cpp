class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Custom comparator for max-heap
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // Prefer smaller number if diff same
            return a.first < b.first; // Max-heap based on diff
        };

        // Priority queue with custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < arr.size(); ++i) {
            int diff = abs(x - arr[i]);
            pq.push({diff, arr[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end()); // Optional if sorted output is required
        return ans;
    }
};