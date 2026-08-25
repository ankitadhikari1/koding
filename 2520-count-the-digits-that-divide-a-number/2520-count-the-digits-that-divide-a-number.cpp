class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int temp = num;
        while(temp){
            int r = temp%10;
            if(num%r==0){
                cnt++;
            }
            temp/=10;
        }
        return cnt;
    }
};