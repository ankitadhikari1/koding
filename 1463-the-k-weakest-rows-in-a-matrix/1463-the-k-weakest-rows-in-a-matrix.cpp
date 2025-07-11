class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int cnt = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)cnt++;
            }
            pq.push({cnt,i});
        }

        vector<int>ans;
        for(int i=0;i<k;i++){
            int ind = pq.top().second;
            ans.push_back(ind);
            pq.pop();
        }
        return ans;
    }
};