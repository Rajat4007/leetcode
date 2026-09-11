class Solution {
public:
    int find_len(int x){
        int count = 0;
        while(x>0){
            x = x/10;
            count++;
        }
        return count;
    }
    int ans = 0;
    int findNumbers(vector<int>& nums) {
        for(int num :nums){
            int len = find_len(num);
            if(len%2 == 0) ans++;
        }
    return ans;
    }
};