class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto & it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int cost = q.top().first;
            q.pop();
            for(auto & it : adj[node]){
                int currNode = it.first;
                int currCost = it.second;
                if(currCost+cost<dist[currNode]){
                    dist[currNode] = currCost + cost;
                    q.push({currCost+cost,currNode});
                }
            }
        }

        int maxTime = INT_MIN;

        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            maxTime = max(maxTime, dist[i]);

        }

        return maxTime;
    }
};