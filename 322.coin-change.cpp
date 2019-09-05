/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (31.60%)
 * Likes:    2151
 * Dislikes: 83
 * Total Accepted:    235K
 * Total Submissions: 742.5K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
// 递归+剪枝

public:
    int coinChange(vector<int>& coins, int amount) {
        memo=vector<int>(amount+1,-1);
        int count=coinCount(coins,amount);
        if(count==INT_MAX) return -1;
        return count;
    }

private:
    vector<int> memo; // memory 达到amount 所需的最小的coin数量
    int coinCount(vector<int>& coins, int amount) {
        if (amount < 0) {
            return INT_MAX;
        }

        if (memo[amount] != -1) {
            return memo[amount];
        }

        if (amount == 0) {
            return 0;
        }

        int count = INT_MAX;
        for(int i=0;i<coins.size();++i){
            count=min(count,coinCount(coins,amount-coins[i]));
        }
        if(count!=INT_MAX) {
            return memo[amount]=count+1;
        }
        return memo[amount]=count;
    }
};

