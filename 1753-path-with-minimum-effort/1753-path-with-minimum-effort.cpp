class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

       
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();
            if(row == n-1 && col == m-1) return diff; 

            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newEffort = max(diff, abs(heights[nx][ny] - heights[row][col]));
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        return -1; 
    }
};
