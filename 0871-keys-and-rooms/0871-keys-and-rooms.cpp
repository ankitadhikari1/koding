class Solution {
public:

    void bfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node] = 1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto & it : adj[val]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }



    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i][j]!=i){
                    adj[i].push_back(rooms[i][j]);
                }
            }
        }

        vector<int>vis(n,0);
        bfs(0,vis,adj);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};