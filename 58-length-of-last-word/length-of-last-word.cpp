class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int l=n-1,r = n-1;
        while( r>=0 && s[r] == ' '){
            l--;r--;
        }
        while(l>=0 && s[l] != ' '){
            l--;
        }
        int count = r-l;
        return count;
    }
};