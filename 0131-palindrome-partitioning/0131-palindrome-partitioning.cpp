class Solution {
public:

    bool palcheck(string s){
        int n= s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>>ans;
    void func(int ind , string &s, vector<string>pal){
        if (ind == s.size()) {
            ans.push_back(pal);
            return;
        }
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(palcheck(temp)){
                pal.push_back(temp);
                func(i+1,s,pal);
                pal.pop_back();
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        vector<string>pal;
        func(0,s,pal);
        return ans;
    }
};