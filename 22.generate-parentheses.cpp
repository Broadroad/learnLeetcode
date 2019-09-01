#include <stack> 
#include <vector>
#include <set>
#include <iostream>
using namespace std;
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
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n < 1) {
            return ret;
        }

        string str = "";
        for (int i = 0; i < n; i++) {
            str += "()";
        }

        string path = "";
        set<string> result;
        DFS(str, 0, path, result);
        ret.resize(result.size());
        copy(result.begin(), result.end(), ret.begin());
        return ret;
    }

    bool isValid(string str) {
        stack<char> brackets;
    
        for (char c : str) {
            if (c == '(') {
                brackets.push(c);
            } else {
                if (!brackets.empty()) {
                    char ch = brackets.top();
                    brackets.pop();
                    if (ch == ')') {
                        return false;
                    }
                    continue;
                }
                return false;
            }
        }
        
        if (brackets.empty()) {
            return true;
        }
        return false;
    }

    void DFS(string s, int pos, string path, set<string> &result) {
        if (pos == s.size()) {
            
            if (isValid(path)) {
                result.insert(path);
            }
            return;
        } 

        for (int i = pos; i < s.size(); i++) {
            path.push_back(s[i]);
            DFS(s, pos+1, path, result);
            path.pop_back();
        };        
    }
};


int main() {
    Solution s;
    vector<string> r = s.generateParenthesis(5);
    for (auto str : r) {
        cout << str << endl;
    }
}

