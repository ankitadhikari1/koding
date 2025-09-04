class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = edges.size();
        int v = vals.size();
        vector<vector<int>>adj(v);
        
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(vals[v]);
            adj[v].push_back(vals[u]);
        }
        for(auto & it : adj){
            sort(it.begin(),it.end(),greater<int>());
        }
        int maxSum = INT_MIN;
        for(int i=0;i<v;i++){
            int sum = vals[i];
            for(int j=0;j<k && j<adj[i].size() && adj[i][j]>0;j++){
                sum+=adj[i][j];
            }
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};