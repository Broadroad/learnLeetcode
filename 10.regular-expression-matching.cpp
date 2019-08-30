/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.60%)
 * Likes:    2950
 * Dislikes: 559
 * Total Accepted:    334.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }

    bool isMatch(string &s, string& p, int cur_s, int cur_p) {
        int sn = s.size(), pn = p.size();
        if (pn == cur_p) {
            return sn == cur_s;
        }

        if (p[cur_p + 1] == '*') {
            if (isMatch(s,p,cur_s,cur_p+2) ||
                (cur_s < sn && (p[cur_p] == '.' || s[cur_s] == p[cur_p]) && isMatch(s,p,cur_s+1,cur_p))) {
                return true;
            }
                
        } else if (cur_s < sn && (s[cur_s] == p[cur_p] || p[cur_p] == '.')) {
            if (isMatch(s, p, cur_s+1, cur_p+1)) {
                return true;
            }
        }
        return false;
    }
};

