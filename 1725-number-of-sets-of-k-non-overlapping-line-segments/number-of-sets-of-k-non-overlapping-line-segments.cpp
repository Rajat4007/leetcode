class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2); // Fermat's Little Theorem
    }

public:
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        if (R > N) return 0;

        // Calculate C(N, R) % MOD
        long long num = 1;
        long long den = 1;

        for (int i = 1; i <= R; ++i) {
            num = (num * (N - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }
};