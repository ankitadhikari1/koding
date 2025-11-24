class Solution {
public:

    long long recurse(const string &s, int i, long long num, int sign) {
        // stop if non-digit
        if (i >= (int)s.size() || !isdigit(s[i]))
            return num * sign;

        // convert char to digit and update
        int d = s[i] - '0';

        long long next = num * 10 + d;

        // check overflow while positive
        if (sign == 1 && next >= INT_MAX)
            return INT_MAX;

        // check underflow while negative
        if (sign == -1 && -next <= INT_MIN)
            return INT_MIN;

        return recurse(s, i + 1, next, sign);
    }


    int myAtoi(string s) {
    
        int i = 0;
        int n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Call recursive helper starting here
        long long ans = recurse(s, i, 0, sign);
        return ans;
    }
};