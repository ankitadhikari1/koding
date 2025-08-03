class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};


        while(!pq.empty()){
            auto  node = pq.top();
            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;
            pq.pop();

            if(row== n-1 && col == m-1){
                return diff;
            }


            for(int i=0;i<4;i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int currDiff = max(abs(heights[row][col]-heights[nx][ny]),diff);
                    if(currDiff<dist[nx][ny]){
                        dist[nx][ny] = currDiff;
                        pq.push({currDiff,{nx,ny}});
                    }
                    
                }
            }


            

        }
        return -1;

    }
};