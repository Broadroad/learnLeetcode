class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        // dp[i][j] -> A 的 前i个字符和B的前j个字符的LCS的长度

        int m = A.size();
        int n = B.size();
        if (m == 0 || m == 0) {
            return 0;
        }

        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
                } 
            }
        }
        return dp[m][n];
    }
};