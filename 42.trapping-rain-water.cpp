/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (45.51%)
 * Likes:    4858
 * Dislikes: 85
 * Total Accepted:    378.9K
 * Total Submissions: 831.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap1(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            int maxLeft = height[i];
            int maxRight = height[i];
            while(left > 0) {
                left--;
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                }
            }

            while (right < n - 1) {
                right++;
                if (height[right] > maxRight) {
                    maxRight = height[right];
                }
            }
            ans += min(maxLeft, maxRight) - height[i];
        }
        return ans;
    }

    int trap2(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }

        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        for (int i = 1; i < n-1; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    int trap(vector<int>& height) {

    }
};
// @lc code=end

