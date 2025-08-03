class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         vector<pair<int,int>>adj[n];
        for(auto & it : flights ){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops>K)continue;
            for(auto & it : adj[node]){
                int currNode = it.first;
                int currCost = it.second;
                if(cost + currCost < dist[currNode] && stops<=K){
                    dist[currNode] = cost + currCost;
                    q.push({stops+1,{currNode,dist[currNode]}});
                }
            }
        }


        return dist[dst]==1e9?-1:dist[dst];
    }
};