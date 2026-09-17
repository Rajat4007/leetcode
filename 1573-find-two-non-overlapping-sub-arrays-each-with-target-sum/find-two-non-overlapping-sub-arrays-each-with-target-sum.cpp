class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, INT_MAX);
        vector<int> suffix(n, INT_MAX);

        // pehle prefix min ko build kro
        int left = 0, sum = 0, prefix_min = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                prefix_min = min(prefix_min, right - left + 1);
            }
            prefix[right] = prefix_min;
        }

        //fir suffix min ko build kro 
        int right = n - 1;
        sum = 0;
        int suffix_min = INT_MAX;
        for (int left = n - 1; left >= 0; left--) {
            sum += arr[left];
            while (sum > target) {
                sum -= arr[right];
                right--;
            }
            if (sum == target) {
                suffix_min = min(suffix_min, right - left + 1);
            }
            suffix[left] = suffix_min;
        }

        // ab search kro dono ka sum se 
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] != INT_MAX && suffix[i + 1] != INT_MAX) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        if(ans != INT_MAX) return ans;
        return -1;
    }
};