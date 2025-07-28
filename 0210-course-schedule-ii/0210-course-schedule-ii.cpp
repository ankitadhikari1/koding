class Solution {

private:
   vector<int>topoSort(int n,vector<int>adj[]){
        vector<int>ans;
        vector<int>inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto & it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto & it :adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }

        }

        return ans;
    }



public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        vector<int>adj[N];
        for(auto & it : arr){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>topo = topoSort(N,adj);
        reverse(topo.begin(),topo.end());
        if(topo.size()<N)return {};
        return topo ;
        
    }
};