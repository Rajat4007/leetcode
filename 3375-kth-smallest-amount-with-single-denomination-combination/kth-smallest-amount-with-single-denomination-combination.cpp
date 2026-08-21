class Solution {
    long long gcd(long long a, long long b) {
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    long long lcm(long long a, long long b) {
        long long res = (a*b)/(gcd(a,b));
        return res;
    }

    long long countMultiples(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int subset = 1; subset < (1 << n); subset++) {
            long long curr_lcm = 1;
            int bit_count = 0;
        
            for (int i = 0; i < n; i++) {
                if (subset & (1 << i)) {
                    bit_count++;
                    curr_lcm = lcm(curr_lcm, coins[i]);
                    
                }
            }

            if (bit_count % 2 == 1) {
                total += x / curr_lcm;
            } else {
                total -= x / curr_lcm;
            }
        }
        return total;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};