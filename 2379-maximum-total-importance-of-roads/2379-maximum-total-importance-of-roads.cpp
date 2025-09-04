class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (int i = 0; i < (int)roads.size(); ++i) {
            int u = roads[i][0];
            int v = roads[i][1];
            ++degree[u];
            ++degree[v];
        }

        
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[degree[i]].push_back(i);
        }

        unordered_map<int, int> rank;
        int r = 1; 
        for (auto &it : mp) {
            for (int node : it.second) {
                rank[node] = r++;
            }
        }

        long long cnt = 0; 
        for (int i = 0; i < (int)roads.size(); ++i) {
            cnt += (long long)rank[roads[i][0]] + rank[roads[i][1]];
        }
        return cnt;
    }
};
