class Solution {
public:

    int findMaxElementRow(vector<vector<int>>&mat, int col){
        int maxEle = mat[0][col];
        int maxInd = 0;

        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>maxEle){
                maxEle = mat[i][col];
                maxInd = i;
            }
        }

        return maxInd;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0 , high =  m-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int row = findMaxElementRow(mat,mid);
            int left = mid-1>=0?mat[row][mid-1]:-1;
            int right = mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};