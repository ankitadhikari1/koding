class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.size();i++){
            if(word[i] == ch){
                reverse(word.begin(),word.begin()+1+i);
                break;
            }
        }
        return word;
    }
};