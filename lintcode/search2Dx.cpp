class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int x = matrix.size();
        if (x == 0) {
            return false;
        }
        
        int startX = 0, endX = x - 1;
        while (startX + 1 < endX) {
            int midx = startX + (endX - startX) / 2;
            if (matrix[midx][0] == target) {
                return true;
            } else if (matrix[midx][0] < target) {
                startX = midx;   
            } else {
                endX = midx;
            }
        }
        
        int row = 0;
        
        if (matrix[endX][0] <= target) {
            row = endX; 
        } else if (matrix[startX][0] <= target) {
            row = startX;
        } else {
            return false;
        }
        
        int startY = 0, endY = matrix[row].size()-1;
        while (startY + 1 < endY) {
            int midy = startY + (endY - startY) / 2;
            if (matrix[row][midy] == target) {
                return true;
            } else if (matrix[row][midy] < target) {
                startY = midy;
            } else {
                endY = midy;
            }
        }
        
        if (matrix[row][startY] == target) {
            return true;
        } else if (matrix[row][endY] == target) {
            return true;
        }
        return false;
    }
};