class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum_single = 0;
        int sum_double = 0;
        for(int num:nums){
            if(num<10){
                sum_single += num;
            }else{
                sum_double += num;
            }
        }
        return sum_single != sum_double;
    }
};