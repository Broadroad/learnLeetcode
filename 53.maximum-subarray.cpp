/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.03%)
 * Likes:    5489
 * Dislikes: 231
 * Total Accepted:    686.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    //prefix sum
    int maxSubArray1(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int maxNum = INT_MIN, sum = 0, minSum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxNum = max(maxNum, sum-minSum);
            minSum = min(maxNum, sum);
        }


        return maxNum;
    }

    // greedy
    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }

    // dp[i] 
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> l(n, 0);
        vector<int> m(n, 0);
        l[0] = m[0] = nums[0];

        for (int i = 1; i < n; i++) {
            l[i] = max(l[i-1]+nums[i], nums[i]);
            m[i] = max(l[i], m[i-1]);
        }
        return m[n-1];
    }
};
// @lc code=end

