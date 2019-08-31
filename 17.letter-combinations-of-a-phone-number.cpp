/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.75%)
 * Likes:    2512
 * Dislikes: 330
 * Total Accepted:    435.4K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        vector<string> telephone({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        DFS(digits, 0, path, result, telephone);
        return result;
    }

    void DFS(string digits, int pos, string path, vector<string> &result, vector<string> &telephone) {
        if (pos == digits.size()) {
            result.push_back(path);
            return;
        }

        for (auto c : telephone[digits[pos] - '0']) {
            path.push_back(c);
            DFS(digits, pos+1, path, result, telephone);
            path.pop_back();
        }
    };
};

