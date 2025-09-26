class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int earning = accumulate(gas.begin(),gas.end(),0);
        int spending = accumulate(cost.begin(),cost.end(),0);
        if(earning < spending)return -1;
        int total = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            total = total + gas[i] - cost[i];
            if(total<0){
                total = 0;
                res = i+1;
            }
        }
        return res;
    }
};