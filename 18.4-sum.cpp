/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.30%)
 * Likes:    1220
 * Dislikes: 240
 * Total Accepted:    256.4K
 * Total Submissions: 818.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        
        vector<vector<int>> result;
        for (size_t i = 0; i < len; i++)
        {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int tmp = target - nums[i];
            for (size_t j = i + 1; j < len; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int tmp1 = tmp - nums[j];
                size_t left = j + 1, right = len - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] < tmp1) {
                        left++;
                    } else if (nums[left] + nums[right] > tmp1) {
                        right--;
                    } else {
                        vector<int> a(4, 0);
                        a[0] = nums[i];
                        a[1] = nums[j];
                        a[2] = nums[left];
                        a[3] = nums[right];
                        if (result.size() > 0) {
                            int n = result.size();
                            if (a[0] == result[n-1][0] && a[1] == result[n-1][1] && a[2] == result[n-1][2] && a[3] == result[n-1][3]) {
                                break;
                            }
                        }
                        result.push_back(a);
                        
                        while (left < right && nums[left] == a[2]) left++;
                        while(left < right && nums[right] == a[3]) right--;
                    }
                }
                
            }
        }
        return result;
    }
};

