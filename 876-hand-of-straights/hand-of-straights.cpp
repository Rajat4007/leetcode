class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        for(int num:hand){
            mpp[num]++;
        }
        while(mpp.size() != 0){
            int first = mpp.begin()->first;
            for(int i = first; i<first+groupSize; i++){
                if(mpp.count(i) == 0) return false;
                mpp[i]--;
                if(mpp[i] == 0) mpp.erase(i);
            }
        }
        return true;
    }
};