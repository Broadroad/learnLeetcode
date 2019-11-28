/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.57%)
 * Likes:    1836
 * Dislikes: 87
 * Total Accepted:    88.7K
 * Total Submissions: 290K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        vector<int> nn(nums);
        sort(nn.begin(), nn.end());

        int l = 0, r = n - 1;
        int start = l, end = n - 1;
        int ans = 0;
        bool lflag = true, rflag = true;
        while (l < n) {
            if (nums[l] != nn[l]) {
                start = l;
                break;
            }
            l++;
        }      

        while (r > start) {
            if (nums[r] != nn[r]) {
                end = r;
                break;
            }
            r--;
        }

        if (l == n && r == 0) {
            return 0;
        }
        return end - start + 1;
    }
};
// @lc code=end

