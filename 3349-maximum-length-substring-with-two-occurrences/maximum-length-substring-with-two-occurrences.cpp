class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>hash(26,0);
        int max_len = 0;
        int l=0,r=0;
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[s[r]-'a']>2){
                hash[s[l]-'a']--;
                l++;
            }
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;

    }
};