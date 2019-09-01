#include <stack> 
#include <vector>
#include <set>
// #include <iostream>
// using namespace std;
/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (56.67%)
 * Likes:    3184
 * Dislikes: 196
 * Total Accepted:    382.6K
 * Total Submissions: 674.9K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    // vector<string> generateParenthesis1(int n) {
    //     vector<string> ret;
    //     if (n < 1) {
    //         return ret;
    //     }

    //     string str = "";
    //     for (int i = 0; i < n; i++) {
    //         str += "()";
    //     }

    //     string path = "";
    //     set<string> result;
    //     DFS1(str, 0, path, result);
    //     ret.resize(result.size());
    //     copy(result.begin(), result.end(), ret.begin());
    //     return ret;
    // }

    // bool isValid(string str) {
    //     stack<char> brackets;
    
    //     for (char c : str) {
    //         if (c == '(') {
    //             brackets.push(c);
    //         } else {
    //             if (!brackets.empty()) {
    //                 char ch = brackets.top();
    //                 brackets.pop();
    //                 if (ch == ')') {
    //                     return false;
    //                 }
    //                 continue;
    //             }
    //             return false;
    //         }
    //     }
        
    //     if (brackets.empty()) {
    //         return true;
    //     }
    //     return false;
    // }

    // void DFS1(string s, int pos, string path, set<string> &result) {
    //     if (pos == s.size()) {
            
    //         if (isValid(path)) {
    //             result.insert(path);
    //         }
    //         return;
    //     } 

    //     for (int i = pos; i < s.size(); i++) {
    //         path.push_back(s[i]);
    //         DFS1(s, pos+1, path, result);
    //         path.pop_back();
    //     };        
    // }

    //  vector<string> generateParenthesis2(int n) {
    //     vector<string> ret;
    //     if (n < 1) {
    //         return ret;
    //     }

    //     string str = "";
    //     for (int i = 0; i < n; i++) {
    //         str += "()";
    //     }
    //     sort(str.begin(), str.end());

    //     set<string> result;
    //     DFS2(str, 0, result);
    //     ret.resize(result.size());
    //     copy(result.begin(), result.end(), ret.begin());
    //     return ret;
    //  }

    //  void DFS2(string s, int pos, set<string> &result) {
    //     if (pos == s.size() - 1) {
    //         if (isValid(s)) {
    //             result.insert(s);
    //         }
    //         return;
    //     } 

    //    for (int i = pos; i < s.size(); i++) {
    //        if (i != pos && s[i] == s[pos]) {
    //            continue;
    //        }
    //        swap(s[i], s[pos]);
    //        DFS2(s, pos+1, result);
    //        swap(s[i], s[pos]);
    //    }       
    // }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS3("", n, n, res);
        return res;
    }

    void DFS3(string s, int opens, int closes, vector<string> &res) {
        if (!opens && !closes) res.push_back(s);
        if (opens) DFS3(s + '(', opens - 1, closes, res);
        if (opens < closes) DFS3(s + ')', opens, closes-1, res);
    }
};


// int main() {
//     Solution s;
//     vector<string> r = s.generateParenthesis1(5);
//     for (auto str : r) {
//         cout << str << endl;
//     }
// }

