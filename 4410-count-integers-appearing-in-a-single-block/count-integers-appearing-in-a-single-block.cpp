class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> first, last, freq;
        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            if(first.find(val) == first.end()){
                first[val] = i;
            }
            last[val] = i;
            freq[val]++;
        }

        int count = 0;
        for(auto it : freq){
            int num = it.first;
            int f = it.second;
            if(last[num] - first[num]+1 == f) count++;
        }
        return count;
    }
};