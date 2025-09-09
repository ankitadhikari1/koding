class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<string> reversestr;
        for(auto x : words){
            string word = x;
            reverse(word.begin(),word.end());
            reversestr.push_back(word);
        }

        int ans = 0;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                if(words[i] == reversestr[j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};