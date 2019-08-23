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

    static bool myfunction (vector<int> num1, vector<int> num2) {
        if (num1.size() != num2.size()) {
            return false;
        }

        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] != num2[i]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int sum1 = 0 - nums[i];
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                int left = sum1 - nums[j];
                for (size_t k = j + 1; k < nums.size(); k++)
                {
                    if (nums[k] == left) {
                        vector<int> triplet(3,0);
                        triplet[0] = nums[i];
                        triplet[1] = nums[j];
                        triplet[2] = nums[k];
                        sort(triplet.begin(), triplet.end());
                        result.push_back(triplet);
                    }
                }
                
            }
        }
        sort(result.begin(), result.end());
        std:vector<vector<int>>::iterator it = unique(result.begin(), result.end(), myfunction);    

        result.resize( std::distance(result.begin(),it) );
        return result;
        
    }
};

