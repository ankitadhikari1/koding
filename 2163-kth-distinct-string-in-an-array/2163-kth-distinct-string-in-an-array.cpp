class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> mp;
        int count = 0;

        
        for (const string& item : arr) {
            if (mp.find(item) != mp.end()) {
                mp[item] = false;  
            } else {
                mp[item] = true;   
            }
        }


        for (auto & it : arr) {
            if (mp[it]) {  
                count++;
                if (count == k) {
                    return it;
                }
            }
        }

        return "";  
    }
};