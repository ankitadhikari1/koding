class Solution {
public:

    void func(int ind , string digits , string temp ,vector<string>&ans,vector<string>&letters ){
        if(ind == digits.size()){
            ans.push_back(temp);
            return;
        }
        int i = digits[ind]-'0';
        for(auto & it : letters[i-2]){
            func(ind+1,digits,temp+it,ans,letters);
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string>letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp = "";
        func(0,digits,temp,ans,letters);
        return ans;
    }
};