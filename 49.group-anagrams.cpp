/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (50.65%)
 * Likes:    2206
 * Dislikes: 137
 * Total Accepted:    432.8K
 * Total Submissions: 854.4K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        if (n == 0) {
            vector<string> a;
            ans.push_back(a);
            return ans;
        }

        sort(strs.begin(), strs.end());
        map<string, vector<string>> m;
        for (auto str: strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            if (m.count(str) == 0) {
                vector<string> angs;
                angs.push_back(tmp);
                m[str] = angs;
            } else {
                m[str].push_back(tmp);
            }
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
// @lc code=end

