class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        //suffix_min(from right to left)
        vector<int> min_end(n);
        min_end[n-1] = nums[n-1];
        for(int i= n-2; i>=0; i--){
            min_end[i] = min(nums[i],min_end[i+1]);
        }
        //prefix_max(from left to right)
        int max_start = nums[0];
        for(int i=0; i<n; i++){
            max_start = max(max_start,nums[i]);
            if((max_start-min_end[i])<=k) return i;
        }
        return -1;
        
    }
};