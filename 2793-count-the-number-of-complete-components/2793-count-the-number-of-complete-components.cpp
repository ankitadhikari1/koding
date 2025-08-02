class Solution {
public:
    void dfs(int u,map<int,vector<int>>& adj,vector<bool>& vis,vector<int>& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (int v:adj[u]) {
            if (!vis[v]) dfs(v,adj,vis,comp);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> adj;
        for (auto &e:edges) {
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n);
        int ans=0;
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i,adj,vis,comp);
                int s=comp.size();
                bool isval=true;
                for(auto u:comp)
                {
                    if(adj[u].size()!=s-1)
                    {
                        isval=false;
                    }
                }
                if(isval)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
