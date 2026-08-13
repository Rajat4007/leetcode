class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int push = 0;
        vector<int> freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        //sort(freq.begin(),freq.end(),greater<int>()); both are similiar for sorting in descending order-> Largest to smallest
        //BY default sort function sort in Ascending Order-> Smalllest to Largest
        sort(freq.rbegin(),freq.rend());
        for(int i=0; i<26; i++){
            if(freq[i] == 0) break;
            push+= ((i/8)+1)*freq[i];
        }
        return push;
    }
};