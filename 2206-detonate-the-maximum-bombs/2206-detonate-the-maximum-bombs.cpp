class Solution {
public:

    int func(int src , vector<vector<int>>&bombs,vector<int>&vis){
       
        vis[src] = 1;
        long long sx = bombs[src][0];
        long long sy = bombs[src][1];
        long long sr = bombs[src][2];
        int count = 1; 
        for(int i=0;i<bombs.size();i++){
            if (vis[i]) continue;
            long long dx = (long long)bombs[i][0] - sx;  
            long long dy = (long long)bombs[i][1] - sy;  
            long long d2 = dx * dx + dy * dy;            
            long long r2 = sr * sr;                     

            if (d2 <= r2) {
                count += func(i, bombs, vis);
            }
        }
        return count;
    }


    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            ans = max(ans,func(i,bombs,vis));
        }
        return ans;
    }
};