class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int stair1 = 1;
        int stair2 = 2;
        int total = 0;
        for(int i=3;i<=n;i++){
            total = stair2 + stair1;
            stair1 = stair2;
            stair2 = total;

        }
        return total;
    }
};