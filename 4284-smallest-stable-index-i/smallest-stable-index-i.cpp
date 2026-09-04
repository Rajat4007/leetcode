class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max = -1,min = INT_MAX;
        for(int i=0; i<n; i++){
            auto max_it = max_element(nums.begin(),nums.begin()+i+1);
            int max_num = *max_it;
            auto min_it = min_element(nums.begin()+i,nums.end());
            int min_num = *min_it;
            int score = max_num - min_num;
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};