class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int temp = x;
        while(temp){
            int r = temp%10;
            sum+=r;
            temp/=10;
        }

        return x%sum==0?sum:-1;
    }
};