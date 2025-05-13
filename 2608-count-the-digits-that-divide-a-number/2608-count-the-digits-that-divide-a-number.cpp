class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int count = 0;
        while(temp){
            int r = temp % 10;
            if(num%r==0)count++;
            temp/=10;
        }
        return count;
    }
};