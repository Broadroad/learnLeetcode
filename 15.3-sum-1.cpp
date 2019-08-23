/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.90%)
 * Likes:    4319
 * Dislikes: 495
 * Total Accepted:    619.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            int temp = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > temp) {
                    right--;
                } else if (nums[left] + nums[right] < temp) {
                    left++;
                } else {
                    vector<int> triplet(3,0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    result.push_back(triplet);
                    while(left < right && nums[left] == triplet[1]) left++;
                    while(left < right && nums[right] == triplet[2]) right--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};

