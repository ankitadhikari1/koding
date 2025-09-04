class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> degree(n, 0);          
        for (int i = 0; i < n; ++i) {
            degree[edges[i]] += i;
        }
        return int(max_element(degree.begin(), degree.end()) - degree.begin()); 
    }
};
