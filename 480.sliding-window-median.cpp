/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 *
 * https://leetcode.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (34.79%)
 * Likes:    588
 * Dislikes: 62
 * Total Accepted:    36.9K
 * Total Submissions: 106K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples:
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Your job is to output the median array for each window in the
 * original array.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 *
 * Window position                Median
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 *
 *
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 *
 * Note:
 * You may assume k is always valid, ie: k is always smaller than input array's
 * size for non-empty array.
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k || nums.size() == 0) {
            return {};
        }
        vector<double> ans;
        multiset<int> maxQ;
        multiset<int> minQ;

        for (int i = 0; i < k; i++) {
            maxQ.insert(nums[i]);
        }

        for (int i = 0; i < k / 2; i++) {
            auto m = maxQ.rbegin();
            minQ.insert(*m);
            maxQ.erase(maxQ.lower_bound(*m));
        }
        
        for (int i = k; i < nums.size(); i++) {
            if (k % 2 == 0) {
                ans.push_back((*maxQ.rbegin() * 0.5 + *minQ.begin() * 0.5));
            } else {
                ans.push_back(*maxQ.rbegin());
            }
            if (maxQ.find(nums[i-k]) != maxQ.end()) {
                maxQ.erase(maxQ.find(nums[i-k]));
                maxQ.insert(nums[i]);
            } else {
                minQ.erase(minQ.find(nums[i-k]));
                minQ.insert(nums[i]);
            }
            
            if (maxQ.size() > 0 && minQ.size() > 0 && *maxQ.rbegin() > *minQ.begin()) {
                int tmp = *maxQ.rbegin();
                maxQ.erase(maxQ.lower_bound(*maxQ.rbegin()));
                maxQ.insert(*minQ.begin());
                minQ.erase(minQ.begin());
                minQ.insert(tmp);
            }
        }
        if (k % 2 == 0) {
            ans.push_back((*maxQ.rbegin() * 0.5 + *minQ.begin() * 0.5));
        } else {
            ans.push_back(*maxQ.rbegin());
        }
        return ans;
    }
};
// @lc code=end

