

class Solution {
   public:
    int ladderLength(string startWord, string targetWord,vector<string> &wordList) {

        set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string original = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(original == targetWord)return steps;
            for(int i=0;i<original.size();i++){
                char last = original[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    original[i] = ch;
                    if(st.find(original)!=st.end()){
                        q.push({original,steps+1});
                        st.erase(original);
                    }
                }
                original[i] = last;
            }
        }

        return 0;



    }
};