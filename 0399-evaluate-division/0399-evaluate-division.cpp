class Solution {
public:

    void dfs(string src , string dst , double&ans , double prod ,unordered_set<string>&vis,unordered_map<string, vector<pair<string,double>>>& adj ){
        if(adj.find(src)==adj.end()){
            return;
        }
        if(src == dst){
            ans = prod;
            return;
        }
        if(vis.count(src))return;
        vis.insert(src);
        for(auto & it : adj[src]){
            dfs(it.first,dst,ans,prod * it.second,vis,adj);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        int n = equations.size();
        for(int i=0;i<n;i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        
        vector<double>answer;
        for(int i=0;i<queries.size();i++){
            unordered_set<string>vis;
            string src = queries[i][0];
            string dst = queries[i][1];
            double ans = -1;
            double prod = 1;
            dfs(src,dst,ans,prod,vis,adj);
            answer.push_back(ans);
        }
        return answer;
    }
};