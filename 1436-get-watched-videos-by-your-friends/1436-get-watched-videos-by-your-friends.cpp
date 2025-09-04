class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(id);
        vis[id] = 1;
        int lvl = 0;
        map<string,int>mp;
        while(!q.empty()){
            int size = q.size();
            if(lvl == level){
                for(int i=0;i<size;i++){
                    int frnd = q.front();
                    q.pop();
                    for(auto & it : watchedVideos[frnd]){
                        mp[it]++;
                    }
                }
                break;
            }
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(auto & it : friends[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            lvl++;
        }


        vector<string>ans;
        for(auto & it : mp){
            ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end(), [&](const string& a, const string& b) {
            if (mp[a] != mp[b]) return mp[a] < mp[b];
            return a < b;
        });
        return ans;
        
    }
};