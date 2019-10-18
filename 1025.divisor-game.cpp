/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (65.10%)
 * Likes:    153
 * Dislikes: 447
 * Total Accepted:    24.2K
 * Total Submissions: 37.2K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */
class Solution {
public:
    bool divisorGame(int N) {
        // dp[i] means number i is true or false when first man start
        /*
        bool dp[N+1];
        memset(dp, 0, N+1);
        dp[0] = false;
        dp[1] = false;

        for (int i = 2; i <= N; i++) {
            for (int j = 1; j * j < i; j++) {
                if (i % j == 0 && !dp[i-j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[N];
        */
       return (N % 2) == 0;
    }
};

