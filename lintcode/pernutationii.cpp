class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> results;
        vector<int> result;
        if (nums.size() == 0) {
            results.push_back(result);
            return results;
        }
        
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, results, result, 0, visited);
        return results;
    }
    
private:
    void dfs(vector<int> &nums, vector<vector<int>> &results, vector<int> &result, int index, vector<bool> visited) {
        if (result.size() == nums.size()) {
            results.push_back(result);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                continue;
            }
            
            if (i != 0 && nums[i] == nums[i-1] && !visited[i - 1]) {
                continue;
            }
            
            result.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, results, result, i+1, visited);
            visited[i] =false;
            result.pop_back();
        }
    }
};