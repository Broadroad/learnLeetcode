/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.40%)
 * Likes:    2350
 * Dislikes: 73
 * Total Accepted:    386.7K
 * Total Submissions: 766.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> results;
        if (candidates.size() == 0) {
            return results;
        }

        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(results, candidates, nums, target, 0, 0);
        return results;
    }

private:
    void combinationSumHelper(vector<vector<int>>& results, vector<int>& candidates, vector<int>& nums, int target, int pos, int sum) {
        if (sum == target) {
            results.push_back(nums);
            return;
        }

        if (target < sum || pos == candidates.size()) {
            return;
        }

        nums.push_back(candidates[pos]);
        combinationSumHelper(results, candidates, nums, target, pos, sum+candidates[pos]);
        nums.pop_back();

        combinationSumHelper(results, candidates, nums, target, pos+1, sum);

    }
};

