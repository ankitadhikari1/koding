class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(auto & it : arr){
            mp[it]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto & it : mp){
            pq.push({it.second,it.first});
        }

        int ans = 0;
        int temp = n;
        while(!pq.empty()){
            int freq = pq.top().first;
            pq.pop();
            temp = temp - freq;
            ans++;
            if(temp <= n / 2)break;
        }

        return ans;

    }
};