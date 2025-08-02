class Solution {
public:

    bool func(int origin ,vector<int>&vis , vector<int>adj[] ){
        vector<int>track;
        track.push_back(origin);
        queue<int>q;
        vis[origin] = 1;
        q.push(origin);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto & it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    track.push_back(it);
                    q.push(it);
                }
            }
        }
        int size = track.size() - 1;
        for(int i=0;i<=size;i++){
            if(adj[track[i]].size()!=size){
                return false;
            }
        }
        return true;
    }
    


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto & it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool check = func(i,vis,adj);
                if(check){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};


