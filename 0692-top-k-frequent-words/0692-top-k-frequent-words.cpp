class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto & it : words){
            mp[it]++;
        }

        auto cmp = [](pair<int,string>& a , pair<int,string>&b ){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        };

        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)>pq(cmp);
        for(auto & it : mp){
            string val = it.first;
            int freq = it.second;
            pq.push({freq,val});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};