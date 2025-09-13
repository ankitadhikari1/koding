class Solution {
public:
    char findTheDifference(string s, string t) {
        int temp = 0;
        for(auto & it : s){
            temp^=it;
        }
        for(auto & it : t){
            temp^=it;
        }
        return temp;
    }
};