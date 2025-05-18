class Solution {
public:
    vector<int> func(int r){
        int temp = 1;
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<r;i++){
            temp = temp * (r-i);
            temp = temp / i;
            ans.push_back(temp);
        }
        return ans;
    }


    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(func(i));
        }
        return ans;
    }
};