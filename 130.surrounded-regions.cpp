/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (24.86%)
 * Likes:    1073
 * Dislikes: 520
 * Total Accepted:    176.8K
 * Total Submissions: 711K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;

        if (!m || !n) return;

        for (int i = 0; i < m; i++) {
            bfs(board, i, 0);
            bfs(board, i, n-1);
        }

        for (int i = 0; i < n; i++) {
            bfs(board, 0, i);
            bfs(board, m-1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << board[i][j];
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void bfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        if (board[x][y] == 'X') {
            return;
        }

        queue<pair<int, int>> Q;
        Q.push(make_pair(x, y));

        while (!Q.empty()) {
            auto node = Q.front();
            Q.pop();
            board[node.first][node.second] = 'T';

            for (int i = 0; i < 4; i++) {
                int next_x = node.first + dx[i];
                int next_y = node.second + dy[i];

                if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && board[next_x][next_y] == 'O') {
                    Q.push(make_pair(next_x, next_y));
                    board[next_x][next_y] = 'T';
                }
            }
        }
    }
};
// @lc code=end

