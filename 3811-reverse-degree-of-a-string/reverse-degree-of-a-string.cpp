class Solution {
public:
    int reverseDegree(string s) {
        int idx = 1;
        int sum = 0;
        for(char c:s){
            int val = abs(c-'z')+1;
            int product = val*idx;
            sum+=product;
            idx++;
        }
        return sum;
    }
};