class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int n = nums.size();
        bool all_zero = true;
        //check kahi sara element zero toh nahi hai 
        for(int i=0; i<n; i++){
            total_xor ^= nums[i];
            if(nums[i] != 0) all_zero = false;
        }
        if(total_xor!=0) return n;
        if(all_zero) return 0;
        return n-1;

    }
};