class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> results;
        if (s.size() == 0) {
            return results;
        }

        vector<string> result;
        dfs(s, results, result, 0);
        return results;
    }

private:
    void dfs(string &s, vector<vector<string>> &results, vector<string>& result, int index) {
        if (index == s.size()) {
            results.push_back(result);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string sub = s.substr(index, i+1-index);
            if (!isPalindor(sub))
                continue;

            result.push_back(sub);
            dfs(s, results, result, i+1);
            result.pop_back();
            
        }
    }

    bool isPalindor(string &s) {
        int len = s.size();
        bool flag = true;

        int i = 0, j = len-1;
        for (int i = 0; i <= j; i++,j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};