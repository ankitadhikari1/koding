class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ind = -1;
        if(ruleKey == "type")ind = 0;
        if(ruleKey == "color")ind = 1;
        if(ruleKey == "name")ind = 2;
        int cnt = 0;
        for(auto & it:items){
            if(it[ind]==ruleValue){
                cnt++;
            }
        }
        return cnt;

    }
};