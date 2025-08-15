class Solution {

private:


public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        vector<int>adj[N];
        vector<int>indegree(N);
        
          for(auto & it : arr){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
          }
        

        queue<int>q;
        for(int i=0;i<indegree.size();i++){
          if(indegree[i]==0){
            q.push(i);
          }
        }

        vector<int>ans;
        while(!q.empty()){
          int node = q.front();q.pop();
          ans.push_back(node);
          for(auto & it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
              q.push(it);
            }
          }
        }


        
        if(ans.size()<N)return {};
        return ans;

        
    }
};