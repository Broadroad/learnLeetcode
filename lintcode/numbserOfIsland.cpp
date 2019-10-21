
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if (grid.size() == 0) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        int island = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    bfsGrid(i, j, grid);
                    island++;
                }
            }
        }

        return island;
    }

private:
    void bfsGrid(int x, int y, vector<vector<bool>> &grid) {
        int directionX[] = {0,1,-1,0};
        int directionY[] = {1,0,0,-1};

        queue<Point> Q;
        Q.push(Point(x,y));
        grid[x][y] = 0;

        while (!Q.empty()) {
            Point p = Q.front();
            Q.pop();

            for (int i = 0; i < 4; i++) {
                if (!isInBound(p.x + directionX[i], p.y + directionY[i], grid)) {
                    continue;
                }
                
                if (grid[p.x+directionX[i]][p.y+directionY[i]]) {
                    Point point(p.x + directionX[i], p.y + directionY[i]);  
                    Q.push(point);
                    grid[p.x+directionX[i]][p.y+directionY[i]] = 0;
                }
            }
        }
    }

    bool isInBound(int x, int y, vector<vector<bool>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};