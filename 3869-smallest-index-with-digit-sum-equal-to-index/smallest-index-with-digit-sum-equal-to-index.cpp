class Solution {
public:
int get_sum(int n){
    int total = 0;
    while(n>0){
        int rem = n%10;
        total+=rem;
        n=n/10;
    }
    return total;
}
    int smallestIndex(vector<int>& nums) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(int i =0;i<nums.size();i++){
            if(i == get_sum(nums[i])){
                return i;
                break;
            }
        }
        return -1;
    }
};