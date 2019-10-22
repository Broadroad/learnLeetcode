class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> results;
        if (candidates.size() == 0) {
            return results;
        }
        
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, result, results);

        return results;
    }

private:
    void dfs (vector<int> &candidates, int target, int index, vector<int> result, vector<vector<int>> &results) {
        if (target == 0) {
            results.push_back(result);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (i != 0 && candidates[i] == candidates[i-1]) {
                continue;
            }

            result.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, result, results);
            result.pop_back();
        }
    }
};