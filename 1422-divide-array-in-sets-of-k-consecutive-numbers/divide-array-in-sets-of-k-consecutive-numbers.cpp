class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        while(mpp.size() != 0){
            int first = mpp.begin()->first;
            for(int i=first; i<first+k; i++){
                if(mpp.count(i) == 0){
                    return false;
                }
                mpp[i]--;
                if(mpp[i] == 0){
                    mpp.erase(i);
                }
            }
        }
        return true;
    }
};