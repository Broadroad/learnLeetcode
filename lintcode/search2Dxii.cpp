class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int result = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int m = row - 1;
        int n = 0;
        
        int start = 0, end = row * col - 1;
        while (m >= 0 && n < col) {
            int number = matrix[m][n];
            if (number < target) {
                n++;
            } else if (number > target) {
                m--;
            } else {
                result++;
                m--;
                n++;
            }
        }
        return result;
        
    }
};