class Solution {
public:
    // Iterative check function
    bool check(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int start = -1;
        int maxSize = 0; // at least 0 initially

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (check(s, i, j)) {
                    if (j - i + 1 > maxSize) {
                        maxSize = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxSize);
    }
};
