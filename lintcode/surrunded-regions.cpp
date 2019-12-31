class UnionFind {
public:
    vector<int> parent;
    int find(int x) {
        if (x == parent[x]) {
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }

    void connect(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y) return;
        parent[root_x] = root_y;
    }

    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;

        if (!m || !n) return;

        UnionFind uf = buildUnionFind(board);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!uf.connected(i*n+j, m*n)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    UnionFind buildUnionFind(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        UnionFind uf(m*n+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (isEdge(m, n, i, j)) {
                        uf.connect(i*n+j, m*n);
                    } else {
                        for (int k = 0; k < 4; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if (insideBoard(m, n, i, j) && board[nx][ny] == 'O') {
                                uf.connect(i*n+j, nx*n+ny);
                            }
                        }
                    }
                }
            }
        }
        return uf;
    }
    bool isEdge (int m, int n, int i, int j) {
        return i == 0 || j == 0 || i == m-1 || j == n-1;
    }

    bool insideBoard(int m, int n, int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
};