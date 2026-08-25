class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        int sm_multiple = k;
        while(st.contains(sm_multiple)){
            sm_multiple+=k;
        }
        
        return sm_multiple;
    }
};