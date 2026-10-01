class Solution {
public:
    bool isValid(string s) {
        // Opening brackets ko store karne ke liye stack
        stack<char> st;

        // String ke har character ko traverse karo
        for (int i = 0; i < s.size(); i++) {

            // Agar opening bracket hai to stack me push kar do
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {

                // Closing bracket mila

                // Agar stack already empty hai to
                // iska matlab matching opening bracket exist hi nahi karta
                if (st.empty())
                    return false;

                // Top opening bracket nikalo
                char c = st.top();
                st.pop();

                // Check karo ki closing bracket
                // aur opening bracket ek pair banate hain ya nahi
                if ((s[i] == ')' && c == '(') ||
                    (s[i] == '}' && c == '{') ||
                    (s[i] == ']' && c == '[')) {

                    // Pair sahi hai.
                    // Kuch karne ki zarurat nahi.
                    // Next character check hoga automatically.
                }
                else {

                    // Pair galat hai
                    return false;
                }
            }
        }

        // Agar traversal ke baad bhi stack me opening brackets bache hain,
        // to unka matching closing bracket nahi mila.
        // Valid tabhi hoga jab stack completely empty ho.
        return st.empty();
    }
};

/*
char c = st.top();
st.pop();

if(
    (s[i]==')' && c!='(') ||
    (s[i]=='}' && c!='{') ||
    (s[i]==']' && c!='[')
){
    return false;
}
*/