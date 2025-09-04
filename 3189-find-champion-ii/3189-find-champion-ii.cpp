class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>degree(n);
        for(int i=0;i<edges.size();i++){
            degree[edges[i][1]]++;
        }
        int champion = -1;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                if(champion != -1)return -1;
                champion = i;
            }

        }
        return champion;
    }
};