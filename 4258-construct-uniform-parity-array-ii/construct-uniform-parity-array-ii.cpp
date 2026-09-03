class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool ans = true;
        int mini = INT_MAX;
        int odd = 0;
        for(int i=0; i<nums1.size(); i++){
            mini = min(mini,nums1[i]);
            if(nums1[i] % 2 != 0) odd = nums1[i];
        }
        if(!odd || mini % 2 != 0) return true;
        return false;
    }
};