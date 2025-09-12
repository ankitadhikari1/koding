class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ind = 0;
    int ans = 0;
    
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0;i<n;i++){
      int sumE = 0;
      for(int j=0;j<m;j++){
        sumE+=(mat[i][j]==1?1:0);
      }
      if(sumE>ans){
        ans = sumE;
        ind = i;
       
      }

    }


    return {ind,ans};
    }
};