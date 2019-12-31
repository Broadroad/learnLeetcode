class UnionFind {
public:
    int count;
    vector<int> parent;

    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        parent.resize(m*n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent[i*n+j] = i*n+j;
                    count++;
                } else {
                    parent[i*n+j] = -1;
                }
            }
        }
    }

    void Union (int i, int j) {
        int parent_i = find(i);
        int parent_j = find(j);

        if (parent_i == parent_j) return;
        parent[parent_i] = parent_j;
        count--;
    }

    int find(int a) {
        if (a == parent[a]) {
            return a;
        }

        return parent[a] = find(parent[a]);
    }

    int getCount() {
        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        if (!m || !n) {
            return 0;
        }

        UnionFind uf(grid);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i-1 >= 0 && grid[i-1][j] == '1') {
                        uf.Union(i*n + j, (i-1)*n + j);
                    }
                    if (j-1 >= 0 && grid[i][j-1] == '1') {
                        uf.Union(i*n + j, i * n + j - 1);
                    }
                    if (i+1 < m && grid[i+1][j] == '1') {
                        uf.Union(i*n + j, (i+1)*n + j);
                    }
                    if (j+1 < n && grid[i][j+1] == '1') { 
                        uf.Union(i*n + j, i*n + j+1);
                    }
                }
            }
        }
        return uf.getCount();
    }
};