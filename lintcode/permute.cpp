class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> visited(nums.size(), false);
        // write your code here
        vector<vector<int>> results;

        vector<int> result;
        dfs(nums, results, result, visited);
        return results;
    }

private:
    void dfs(vector<int> &nums, vector<vector<int>> &results, vector<int> result, vector<bool> & visited) {
        if (result.size() == nums.size()) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            result.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, results, result, visited);
            visited[i] = false;
            result.pop_back();
        }
    }
};