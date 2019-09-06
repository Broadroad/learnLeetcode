/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.19%)
 * Likes:    1026
 * Dislikes: 50
 * Total Accepted:    245.8K
 * Total Submissions: 568.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        if (candidates.size() == 0) {
            return results;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        combinationSum2Helper(results, candidates, nums, 0, target);
        return results;
    }
private:
    void combinationSum2Helper(vector<vector<int>>& results, vector<int>& candidates, vector<int>& nums, int pos, int target) {
        if (target == 0) {
            results.push_back(nums);
            return;
        }

        if (pos >= candidates.size() || target - candidates[pos] < 0) {
            return;
        } 

        for (int i = pos; i < candidates.size(); i++) {
            if (i == pos || candidates[i] != candidates[i-1]) {
                nums.push_back(candidates[i]);
                combinationSum2Helper(results, candidates, nums, i+1, target-candidates[i]);
                nums.pop_back();
            }
        }
    }
};

