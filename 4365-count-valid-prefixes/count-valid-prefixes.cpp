class Solution {
public:
    int countValidPrefixes(string s) {
        int count = 0;
        int zero = 0,n = s.size();
        int one = 0;
        for(int i=0; i<n; i++){
            s[i] == '0' ? zero++ : one++;
            if(abs(zero - one) <= 1) count ++;
        }
        return count;
    }
};