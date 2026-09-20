class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long long count = 0;
        sort(intervals.begin(),intervals.end());
        for(int i=0; i<n; i++){
            int endPointI = intervals[i][1];
            //ab binary search
            int low = i+1;
            int high = n-1;
            int ansIdx = i;
            while(low<=high){
                int mid = low + (high-low)/2;

                if(intervals[mid][0]<=endPointI){
                    ansIdx = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            count += (ansIdx - i);

        }
        return count;
    }
};