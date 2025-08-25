class Solution {
public:

    bool check(int low , int high , string s){
        while(low<high){
            if(s[low]!=s[high])return false;
            low++;
            high--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low<high){
            if(s[low]!=s[high]){
                return check(low+1,high,s) || check(low,high-1,s);
            }
            low++;
            high--;
        }
        return true;
    }
};