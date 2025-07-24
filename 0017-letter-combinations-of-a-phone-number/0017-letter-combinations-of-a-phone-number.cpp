class Solution {
public:

     void func(int ind , string digits ,vector<string>dict, vector<string>&ans,string temp){
        if(ind == digits.size()){
            ans.push_back(temp);
            return ;
        }

        int index = digits[ind] - '0';

        for(int i=0;i<dict[index].size();i++){
            func(ind+1,digits,dict,ans,temp+dict[index][i]);
        }
    }


    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string temp = "";
        func(0,digits,dict,ans,temp);
        return ans;
    }
};