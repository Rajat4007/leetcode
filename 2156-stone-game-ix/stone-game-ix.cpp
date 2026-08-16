class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int rem0 = 0, rem1 = 0, rem2 = 0;
        for (int stone : stones) {
            if (stone % 3 == 0)
                rem0++;
            if (stone % 3 == 1)
                rem1++;
            if (stone % 3 == 2)
                rem2++;
        }
        if (rem1 == 0 && rem2 == 0)
            return false;

        if (rem0 % 2 == 0)
            return rem1 > 0 && rem2 > 0;

        return abs(rem1 - rem2) > 2;
    }
};