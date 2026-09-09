class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        for (long long base = 1000; base <= n; base *= 1000) {
            total += (n - base + 1);
            
        }
        return total;
    }
};