class Solution {
public:
    int reverseDegree(string s) {
         int prod , sum=0;
        for(int i=0;i<s.size();i++){
            prod = (i+1)*(123-s[i]);
            sum+=prod;
        }
        return sum;
    }
};