class Solution {
public:
    bool isPalindrome(int x) {
        bool flag = false;
        if(x<0){
            return false;
        }
        int sum = 0;
        int temp = x;

        while(temp){
            int r = temp % 10;
            if((sum > INT_MAX/10 )||(sum < INT_MIN/10)){
                return false;
            }
            sum = (sum * 10 )+ r;
            temp /= 10;
        }

        return sum == x;
    }
};