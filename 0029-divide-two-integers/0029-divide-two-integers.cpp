class Solution {
public:
    int divide(int dividend, int divisor) {
        // guard divisor == 0 (optional - LeetCode guarantees divisor != 0)
        if (divisor == 0) return INT_MAX;

        // handle trivial case
        if (dividend == divisor) return 1;

        // determine sign of result
        bool positive = ( (dividend >= 0) == (divisor >= 0) );

        // convert to positive long long to avoid overflow with INT_MIN
        long long a = llabs((long long) dividend);
        long long b = llabs((long long) divisor);

        long long quotient = 0;

        // subtract multiples of b using doubling
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;
            // double temp while we can and while it doesn't exceed a
            while ((temp << 1) > 0 && (temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            quotient += multiple;
        }

        
        long long result = positive ? quotient : -quotient;

        // clamp to 32-bit signed int range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int) result;
    }
};
