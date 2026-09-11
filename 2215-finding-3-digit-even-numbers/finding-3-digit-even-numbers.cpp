class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int digit:digits){
            freq[digit]++;
        }

        vector<int> ans;

        for(int i=100; i<999; i+=2){
             int d1 = i/100;
            int d2 = (i/10)%10;
            int d3 = i%10;

            freq[d1]--;
            freq[d2]--;
            freq[d3]--;

            if(freq[d1]>=0 && freq[d2]>=0 && freq[d3]>=0){
                ans.push_back(i);
            }
            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }
        return ans;
    }
};