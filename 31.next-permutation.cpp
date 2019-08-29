#include <algorithm> 
/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.94%)
 * Likes:    2105
 * Dislikes: 666
 * Total Accepted:    264K
 * Total Submissions: 852.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        for (i = nums.size() - 1; i && nums[i-1] >= nums[i]; --i);
        if (i) {
			for (j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
            swap(nums[i-1], nums[j]);
        }
        // 处理特殊case，如果逆序数最大，就全部reverse，返回最小的
		reverse(nums.begin()+(i-1==j?0:i),nums.end());
    }
};
	