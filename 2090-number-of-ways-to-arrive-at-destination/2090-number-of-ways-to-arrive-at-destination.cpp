class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }

        // Distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Min-heap priority queue: {current_time, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Starting point
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();

            // Skip if we've already found a better path
            if (time > dist[node]) continue;

            for (auto& [nei, wt] : adj[node]) {
                long long newDist = time + wt;

                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    ways[nei] = ways[node];
                    pq.emplace(newDist, nei);
                }
                else if (newDist == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
