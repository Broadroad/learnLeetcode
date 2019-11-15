/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.66%)
 * Likes:    2463
 * Dislikes: 109
 * Total Accepted:    227.9K
 * Total Submissions: 854.1K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        
        int result = 0;
        int accum = 0;

        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    accum = 0;
                } else {
                    int start = st.top();
                    st.pop();
                    int maxL = i - start + 1;

                    if (st.empty()) {
                        accum += maxL;
                        maxL = accum;
                    } else {
                        maxL = i - st.top();
                    }
                    result = max(result, maxL);
                }
            }
        }
        return result;
    }
};
// @lc code=end

