/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.51%)
 * Likes:    3575
 * Dislikes: 174
 * Total Accepted:    746.2K
 * Total Submissions: 2M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

// @lc code=start
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
        return st.empty();
    }
};
// @lc code=end

