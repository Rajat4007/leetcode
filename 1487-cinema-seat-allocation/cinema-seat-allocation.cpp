class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>>mpp;
        for(auto &seat : reservedSeats){
            int row = seat[0];
            int seats = seat[1];
            mpp[row].push_back(seats);
        }

        int count = 0;
        for(auto&[row,col] : mpp){
            bool left = true;
            bool right = true;
            bool middle = true;
            for(int s : col){
                if(s>=2 && s<=5) left = false;
                if(s>=4 && s<=7) middle = false;
                if(s>=6 && s<=9) right = false;
            }
            if(left && right) count += 2;
            else if(left || right || middle) count += 1;
        }
        count += 2*(n-mpp.size());
        return count;
    }
};