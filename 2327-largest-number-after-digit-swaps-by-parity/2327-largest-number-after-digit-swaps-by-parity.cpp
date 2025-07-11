class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>odd,even;
        vector<int>odds;
        while(num){
            int r = num % 10;
            if(r&1){
                odd.push(r);
                odds.push_back(1);
            }
            else{
                even.push(r);
                odds.push_back(0);
            }
            num/=10;
        }

        int res = 0;
        for(int i=odds.size()-1;i>=0;i--){
            res*=10;
            if(odds[i]){
                res+=odd.top() ; odd.pop();
            }
            else{
                res+=even.top() ; even.pop();
            }
            
        }
        return res;
    }
};