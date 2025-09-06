class Solution {
public:
    int dfsComputeSubtree(int node, int parent, int depth,
                          vector<vector<int>>& adj,
                          vector<int>& subtreeSize,
                          long long& totalDistanceFromRoot) {
        int size = 1;
        totalDistanceFromRoot += depth;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            size += dfsComputeSubtree(neighbor, node, depth + 1, adj, subtreeSize, totalDistanceFromRoot);
        }

        subtreeSize[node] = size;
        return size;
    }

    void dfsPropagateResult(int node, int parent, int n,
                            vector<vector<int>>& adj,
                            vector<int>& subtreeSize,
                            vector<long long>& distSum) {
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            // Transition formula:
            distSum[neighbor] = distSum[node] - subtreeSize[neighbor] + (n - subtreeSize[neighbor]);

            dfsPropagateResult(neighbor, node, n, adj, subtreeSize, distSum);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subtreeSize(n, 0);
        vector<long long> distSum(n, 0);

        long long totalDistanceFromRoot = 0;

        // Step 1: compute subtree sizes and total distance from root
        dfsComputeSubtree(0, -1, 0, adj, subtreeSize, totalDistanceFromRoot);
        distSum[0] = totalDistanceFromRoot;

        // Step 2: propagate results to all nodes
        dfsPropagateResult(0, -1, n, adj, subtreeSize, distSum);

        // Convert long long → int for final return
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = (int)distSum[i];
        }

        return result;
    }
};
