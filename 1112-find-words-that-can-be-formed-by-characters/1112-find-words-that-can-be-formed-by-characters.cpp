class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for (char ch : chars) { 
            freq[ch - 'a']++;
        }

        int finalCnt = 0; 
        for (int i = 0; i < words.size(); i++) {
            vector<int> temp(26, 0);
            for (char ch : words[i]) {  
                temp[ch - 'a']++;
            }

            bool good = true;
            for(int j = 0; j<26; j++){  
                if(temp[j] > freq[j]){ 
                    good = false;
                    break;
                }
            }

            if(good) finalCnt += words[i].size();
        }
        return finalCnt;
    }
};