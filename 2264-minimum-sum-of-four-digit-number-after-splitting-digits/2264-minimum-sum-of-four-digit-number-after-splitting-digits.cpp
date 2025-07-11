class Solution {
public:
    int minimumSum(int num) {
        int digits[4], i = 0;
        while (num) {
            digits[i++] = num % 10;
            num /= 10;
        }
        sort(digits, digits + 4);
        int new1 = digits[0]*10 + digits[3];
        int new2 = digits[1]*10 + digits[2];
        return new1 + new2;
    }
};