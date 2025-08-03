class Solution {
public:

    bool bfscolor(int i , vector<int>adj[],vector<int>&vis,vector<int>&color){
        color[i] = 0;
        vis[i] = 1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto & it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }

        return true;
    }



    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto & it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bool possible = bfscolor(i,adj,vis,color);
                if(!possible){
                    return false;
                }
            }
        }

        return true;
    }
};