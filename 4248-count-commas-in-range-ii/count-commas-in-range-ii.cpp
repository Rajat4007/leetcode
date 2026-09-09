class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        } else if (n < 1000000) {
            return n - 999;
        } else if (n < 1000000000) {
            return 1LL * 999000 + (n - 999999) * 2;
        } else if (n < 1000000000000LL) {
            return 1LL * 999000 + 2LL * 999000000 + (n - 999999999) * 3;
        } else if (n < 1000000000000000LL) {
            return 1LL * 999000 + 2LL * 999000000 + 3LL * 999000000000LL + (n - 999999999999LL) * 4;
        } else {
            return 1LL * 999000 + 2LL * 999000000 + 3LL * 999000000000LL + 4LL * 999000000000000LL + (n - 999999999999999LL) * 5;
        }
    }
};