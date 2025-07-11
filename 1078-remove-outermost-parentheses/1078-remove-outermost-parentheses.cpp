class Solution {
public:
    string removeOuterParentheses(string s) {
        int count1 = 0, count2 = 0;
        string out;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count1++;
            } else {
                count2++;
            }

            if (count1 == count2) {
                count1 = 0;
                count2 = 0;
            }

            if (count1 != count2 && count1 != 1) {
                out += s[i];
            }
        }

        return out;
    }
};