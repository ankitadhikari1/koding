class Solution {
public:


    void func(vector<bool>& prime, int n) {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
        func(prime,n);
        int ans = 0;
        for(int i=1;i<n;i++){
            if(prime[i])ans++;
        }
        return ans;
    }
};