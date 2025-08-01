class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int>q;
        q.push(1);
        vector<int>min_steps(n*n+1,-1);
        min_steps[1] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=1;i<=6 && x+i <= n * n ;i++){
                int node = x + i;
                int row = (node - 1)/n ;
                int col = (node - 1)%n ;
                int v = board[n-1-row][row%2?n-1-col:col];
                int real_val = v>0?v:node;
                if(real_val==n*n){
                    return min_steps[x]+1;
                }
                if(min_steps[real_val]==-1){
                    min_steps[real_val] = min_steps[x]+1;
                    q.push(real_val);
                }
            }
        }

        return -1;
        
    }
};