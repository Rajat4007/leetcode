class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long pen = total/cost1;
        long long ans = 0;
        for(long long i = 0;i<=pen;i++){
            long long pencil = (total - (cost1*i))/cost2;
            ans += pencil +1;
        }
        return ans;
    }
};