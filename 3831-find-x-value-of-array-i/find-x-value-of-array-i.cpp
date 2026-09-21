#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        // freq[r] store karega ki pichle index par khatam hone wale kitne subarrays ka modulo 'r' tha
        vector<long long> freq(k, 0);

        for (int x : nums) {
            vector<long long> next_freq(k, 0);
            
            // 1. Ek naya subarray jo bas iss single element 'x' se shuru ho raha hai
            int current_rem = x % k;
            next_freq[current_rem]++;

            // 2. Purane saare subarrays ke remainder mein 'x' multiply karke naya remainder nikala
            for (int r = 0; r < k; r++) {
                if (freq[r] > 0) {
                    int new_rem = (1LL * r * x) % k;
                    next_freq[new_rem] += freq[r];
                }
            }

            // 3. Result mein current index par khatam hone wale sare remainders add kar do
            for (int r = 0; r < k; r++) {
                result[r] += next_freq[r];
            }

            // Next element ke liye frequency array update kar do
            freq = move(next_freq);
        }

        return result;
    }
};