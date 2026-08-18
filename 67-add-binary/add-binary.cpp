class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int curr_sum = carry;
            if (i >= 0) {
                curr_sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                curr_sum += b[j] - '0';
                j--;
            }
            result.push_back((curr_sum % 2) + '0');
            carry = curr_sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};