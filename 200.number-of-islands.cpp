/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.61%)
 * Likes:    3604
 * Dislikes: 133
 * Total Accepted:    487K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

// @lc code=start
class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UnionFind(vector<vector<char>> &vec) {
        count = 0;
        int m = vec.size();
        int n = vec[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vec[i][j] == '1') {
                    parent.push_back(i*n+j);
                    count++;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int v) {
        if (parent[v] != v) parent[v] = find(parent[v]);
        return parent[v]; 
    }

    void Union(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else {
                parent[root_y] = root_x; 
                rank[root_x] += 1;
            }
            --count;
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m? grid[0].size() : 0;
        if (!m || !n) {
            return 0;
        }

        UnionFind uf(grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i-1 >= 0 && grid[i-1][j] == '1') uf.Union(i*n+j, (i-1)*n+j);
                    if (j-1 >= 0 && grid[i][j-1] == '1') uf.Union(i*n+j, i*n+j-1);
                    if (i+1 < m && grid[i+1][j] == '1') uf.Union(i*n+j, (i+1)*n+j);
                    if (j+1 < n && grid[i][j+1] == '1') uf.Union(i*n+j, i*n+j+1);
                }
            }
        }
        return uf.getCount();
    }
};
// @lc code=end

