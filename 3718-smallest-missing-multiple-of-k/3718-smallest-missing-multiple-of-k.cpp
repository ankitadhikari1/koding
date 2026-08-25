class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool>mp;
        for(auto num : nums){
            if(num%k==0){
                mp[num/k] = true;
            }
        }

        int i = 1;
        while(true){
            if(mp[i]==false){
                return k * i;
            }
            i++;
        }
    }
};