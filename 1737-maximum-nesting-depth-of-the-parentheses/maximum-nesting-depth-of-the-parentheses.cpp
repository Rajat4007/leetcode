class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int maxDepth= 0;
        for(char x:s){
            if(x == '(') p++;
            else if( x == ')') p--;
            maxDepth = max(maxDepth,p);
        }
        return maxDepth;
    }
};