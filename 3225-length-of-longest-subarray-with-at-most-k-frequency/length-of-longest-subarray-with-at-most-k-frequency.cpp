class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r = 0;
        int n = nums.size();
        unordered_map<int,int>mpp;
        int max_len = 0;
        while(r<n){
            mpp[nums[r]]++;
           while(mpp[nums[r]]>k){
            mpp[nums[l]]--;
            l++;
           }
           max_len = max(max_len,r-l+1);
           r++;
        }
        return max_len;
    }
};