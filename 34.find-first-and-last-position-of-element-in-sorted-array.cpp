#include <algorithm>
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.10%)
 * Likes:    1930
 * Dislikes: 97
 * Total Accepted:    345.3K
 * Total Submissions: 1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        vector<int> result(2,-1);
        int n = nums.size();
        
        if (n == 0) {
            return result;
        }
        
        if (n == 1) {
            if (target == nums[0]) {
                result[0] = 0;
                result[1] = 0;
            } 
            return result;
        }
        
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                start = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        while(start >= 0 && nums[start] == target) {
            start--;
        }
        
        while(end < n && nums[end] == target) {
            end++;
        }
        
        if (nums[start+1] == target) {
            result[0] = start+1;
        } else {
            result[0] = -1;
        }
        
        if (nums[end-1] == target) {
            result[1] = end-1;
        } else {
            result[1] = -1;
        }
        
        return result;
        */
        int idx1 = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int idx2 = std::lower_bound(nums.begin(), nums.end(), target+1)-nums.begin()-1;
        if (idx1 < nums.size() && nums[idx1] == target) {
            return {idx1, idx2};
        } else {
            return {-1, -1};
        }
};

