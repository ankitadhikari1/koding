class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0;
        for(auto & it : s){
            if(it=='('){
                cnt++;
                maxCnt = max(maxCnt,cnt);
            }
            else if(it==')'){
                cnt--;
            }
        }
        return maxCnt;
    }
};