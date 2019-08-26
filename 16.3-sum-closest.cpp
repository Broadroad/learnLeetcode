/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.77%)
 * Likes:    1275
 * Dislikes: 90
 * Total Accepted:    373.5K
 * Total Submissions: 816K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int sum = 0;
        int diff = 0;
        int ret = nums[0] + nums[1] + nums[2];
        int minDiff = abs(ret - target);

        for(int i = 0; i < length - 2; i++) {
            int left = i + 1, right = length - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                diff = abs(sum - target);

                if (diff == 0) {
                    return target;
                }

                if (diff < minDiff) {
                    minDiff = diff;
                    ret = sum;
                }

                if (sum - target > 0) {
                    right--;
                } else {
                    left++;
                }
                
            }
            
        }
        return ret;
    }
};

