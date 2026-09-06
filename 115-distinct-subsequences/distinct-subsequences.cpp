class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        // dp[j] represents the number of distinct subsequences of the current prefix of s that match t[0...j-1]
        // Using unsigned long long to prevent 32-bit integer overflow during intermediate additions
        vector<unsigned long long> dp(n + 1, 0);

        // An empty string t can always be formed by an empty subsequence (1 way)
        dp[0] = 1;

        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through t to use values from the previous row (dp[j-1]) without overwriting them
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};