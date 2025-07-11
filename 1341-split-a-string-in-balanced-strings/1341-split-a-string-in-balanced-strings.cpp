class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int cnt = 0;
        int Sum = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                Sum++;
            }
            else{
                Sum--;
            }
            if(Sum==0)cnt++;
        }
        return cnt;
    }
};