class Solution {
public:
    string reverseParentheses(string s) {
        string current = "";
        stack<string> st;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                // Current level ko save karo
                st.push(current);

                // Naya inner level start
                current = "";
            }

            else if(s[i] == ')') {
                // Inner string ko reverse karo
                reverse(current.begin(), current.end());

                // Previous level wapas lao
                string prev = st.top();
                st.pop();

                // Dono ko combine karo
                current = prev + current;
            }

            else {
                // Normal character
                current += s[i];
            }
        }

        return current;
    }
};