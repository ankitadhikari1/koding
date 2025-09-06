class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr = {".-",   "-...", "-.-.", "-..",  ".",    "..-.",
                              "--.",  "....", "..",   ".---", "-.-",  ".-..",
                              "--",   "-.",   "---",  ".--.", "--.-", ".-.",
                              "...",  "-",    "..-",  "...-", ".--",  "-..-",
                              "-.--", "--.."};
        set<string>st;
        for(auto & it : words){
            string temp = "";
            for(int i=0;i<it.size();i++){
                temp+=arr[it[i]-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};