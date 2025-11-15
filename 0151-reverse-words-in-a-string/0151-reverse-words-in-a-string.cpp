class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();

        // find first non-space index
        int ind = 0;
        while (ind < n && s[ind] == ' ') ind++;
        if (ind >= n) return ""; // string was all spaces

        while (ind < n) {
            // find end of the current word
            int i = ind;
            while (i < n && s[i] != ' ') i++;

            // substring: start at ind, length = i - ind
            words.push_back(s.substr(ind, i - ind));

            // skip spaces to the start of next word
            while (i < n && s[i] == ' ') i++;
            ind = i;
        }

        // join words in reverse order with single spaces
        string ans;
        for (int k = (int)words.size() - 1; k >= 0; --k) {
            if (!ans.empty()) ans += ' ';
            ans += words[k];
        }
        return ans;
    }
};
