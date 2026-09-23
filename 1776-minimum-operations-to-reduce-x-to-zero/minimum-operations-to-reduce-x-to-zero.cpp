class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long target = total_sum - x;
        if (target == 0)
            return nums.size();
        if (target < 0)
            return -1;

        int max_len = -1;
        int left = 0;
        long long current_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];

            while (left <= right && current_sum > target) {
                current_sum -= nums[left];
                left++;
            }

            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }

        if (max_len == -1)
            return -1;
        return nums.size() - max_len;
    }
};