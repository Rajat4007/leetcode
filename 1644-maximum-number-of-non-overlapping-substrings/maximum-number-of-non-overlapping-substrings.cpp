class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) {
                first[idx] = i;
            }
            last[idx] = i;
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < n; ++i) {
            // Only check if 'i' is the first occurrence of s[i]
            if (i == first[s[i] - 'a']) {
                int r = last[s[i] - 'a'];
                bool isValid = true;

                for (int j = i; j <= r; ++j) {
                    // If a character inside needs to start before 'i', invalid
                    // interval
                    if (first[s[j] - 'a'] < i) {
                        isValid = false;
                        break;
                    }
                    // Expand the right boundary to include all occurrences of
                    // s[j]
                    r = max(r, last[s[j] - 'a']);
                }

                if (isValid) {
                    intervals.push_back({i, r});
                }
            }
        }
        // 3. Sort intervals based on their ending index (r)
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // 4. Greedily pick non-overlapping intervals
        vector<string> result;
        int lastEnd = -1;

        for (const auto& [start, end] : intervals) {
            // If this interval starts after the previously chosen one ends
            if (start > lastEnd) {
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }

        return result;
    }
};
