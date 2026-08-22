class Solution {
public:
    bool checkDivisibility(int n) {
        int sumM = 0;
        int prodD = 1;
        int temp = n;
        while (temp > 0) {
            int r = temp % 10;
            sumM += r;
            prodD *= r;
            temp /= 10;
        }
        int total = sumM + prodD;
        return n % total == 0;
    }
};