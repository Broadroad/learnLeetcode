class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
         vector<vector<int> > results;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        helper(results, subset, nums, 0);

        return results;
    }
    
 private:
    void helper(vector<vector<int> > &results,
                vector<int> &subset,
                vector<int> &nums,
                int start) {
        results.push_back(subset);
        
        for (int i = start; i < nums.size(); i++) {
            if (i - 1 >= 0 &&  nums[i] == nums[i-1] && start < i) {
                continue;
            }
            subset.push_back(nums[i]);
            helper(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

