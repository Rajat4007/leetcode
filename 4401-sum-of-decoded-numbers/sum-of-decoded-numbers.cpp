class Solution {
public:
    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod; // Base ko range mein rakhne ke liye

        while (exp > 0) {
            // Agar exponent odd hai, toh result se multiply karo
            if (exp % 2 != 0) {
                res = (res * base) % mod;
            }

            // Base ko square karo aur exponent ko aadha (half) kar do
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum_decoded = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long num = nums[i];
            int width = num % 10;
            long long d = num / 10;
            string d_str = to_string(d);
            long long x = stoll(d_str.substr(0, width));
            long long y = stoll(d_str.substr(width));

            sum_decoded = (sum_decoded + modPow(x, y, mod)) % mod;
        }
        return sum_decoded;
    }
};

/*Floating-Point & Integer Overflow: std::pow(x, y) returns a double and quickly
 * overflows 64-bit integers when $y$ is large (up to $10^9$). You need modular
 * binary exponentiation ((base^exp) % mod).*/