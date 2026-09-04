class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        //suffix_min(from right to left)
        vector<int> min_from_end(n);
        min_from_end[n-1] = nums[n-1];
        for(int i= n-2; i>=0; i--){
            min_from_end[i] = min(nums[i],min_from_end[i+1]);
        }
        //prefix_max(from left to right)
        int max_from_start = nums[0];
        for(int i=0; i<n; i++){
            max_from_start = max(max_from_start,nums[i]);
            int score = max_from_start - min_from_end[i];
            if(score<=k) return i;
        }
        return -1;
        
    }
};