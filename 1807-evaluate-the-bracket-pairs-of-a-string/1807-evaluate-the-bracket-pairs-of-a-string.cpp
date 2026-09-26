class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (const auto& x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans;
        ans.reserve(s.size());

        for (int i = 0; i < s.size();) {
            if (s[i] != '(') {
                ans += s[i++];
                continue;
            }

            int j = i + 1;

            while (s[j] != ')') {
                j++;
            }

            string key = s.substr(i + 1, j - i - 1);

            auto it = mp.find(key);

            if (it != mp.end())
                ans += it->second;
            else
                ans += '?';

            i = j + 1;
        }

        return ans;
    }
};