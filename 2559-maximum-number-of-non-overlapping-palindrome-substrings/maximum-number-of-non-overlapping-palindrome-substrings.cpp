class Solution {
public:
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int i = 0;
        int count = 0;

        while (i <= n - k) {
            // 1. Pehle length k check karo (boundary safe hai kyunki i <= n - k)
            string sub = s.substr(i, k);
            if (isPalindrome(sub)) {
                count++;
                i += k; // Jump past length k
                continue;
            }

            // 2. Agar length k nahi mila, tab length k + 1 check karo
            if (i + k + 1 <= n) {
                string sub2 = s.substr(i, k + 1);
                if (isPalindrome(sub2)) {
                    count++;
                    i += k + 1; // Jump past length k + 1
                    continue;
                }
            }

            // 3. Agar dono me se koi nahi mila, tab sirf 1 step aage badho
            i++;
        }

        return count;
    }
};