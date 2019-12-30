/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.49%)
 * Likes:    3240
 * Dislikes: 239
 * Total Accepted:    311.9K
 * Total Submissions: 950K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) {
            return "";
        }

        // count of different char in t
        int cnt = 0;
        vector<int> mm(256, 0);
        for (char c: t) {
            mm[c]++;
            if (mm[c] == 1) {
                cnt++;
            }
        }

        vector<int> mn(256, 0);
        int now = 0;
        int ansl = -1;
        int ansr = -1;
        for (int i = 0, j = 0; i < m; i++) {
            while (j < m &&  now < cnt) {
                mn[s[j]]++;
                if (mn[s[j]] == mm[s[j]]) {
                    ++now;
                }
                ++j;
            }

            // now j is the next number of the right number here
            if (now == cnt) {
                if (ansl == -1 || j - i < ansr - ansl) {
                    ansr = j;
                    ansl = i;
                }
            }

            --mn[s[i]];
            if (mn[s[i]] == mm[s[i]] - 1) {
                now--;
            }
        }
        if (ansl == -1) {
            return "";
        }
        return s.substr(ansl, ansr - ansl);
    }
};
// @lc code=end

