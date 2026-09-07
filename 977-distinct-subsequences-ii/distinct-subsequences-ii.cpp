class Solution {
public:
    int distinctSubseqII(string s) {
        long long total_subsequences = 1; // Starts with 1 (the empty string "")
        long long MOD = 1e9 + 7;
        
        // Stores the number of subsequences added by each character ('a' through 'z')
        // Initialised to 0 because no letters have added anything yet.
        vector<long long> added_by_char(26, 0);
        
        for (char c : s) {
            int idx = c - 'a'; // Convert character to a 0-25 index
            
            // 1. Calculate how many new strings this character can make.
            // It can combine with every single unique string currently on our board.
            long long new_contributions = total_subsequences;
            
            // 2. Calculate the updated total
            // New Total = Old Total + New Words Created - Old Duplicates from this letter
            long long next_total = (total_subsequences + new_contributions - added_by_char[idx] + MOD) % MOD;
            
            // 3. Update our records for this letter and the total
            added_by_char[idx] = new_contributions;
            total_subsequences = next_total;
        }
        
        // Subtract 1 at the end to exclude the empty string ""
        return (total_subsequences - 1 + MOD) % MOD;
    }
};
