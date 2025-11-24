class Solution {
public:

         int mod = 1000000007;

    long long modPow(long long base, long long exp) {
        long long res = 1 % mod;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long p1 = modPow(5,even);
        long long p2 = modPow(4,odd);

        return (int)((p1*p2)%mod)%mod;
    }
};