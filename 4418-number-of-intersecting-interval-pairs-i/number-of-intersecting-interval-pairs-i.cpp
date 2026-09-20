class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                int starti = intervals[i][0];
                int startj = intervals[j][0];

                int endi = intervals[i][1];
                int endj = intervals[j][1];
                if(max(starti,startj)<=min(endi,endj)){
                    count++;
                }
            }
        }
        return count;
    }
};