class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }

            if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                    continue;
                }
                return false;
            }

            if (s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                    continue;
                }
                return false;
            }

            if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        return s.empty();
    }
};