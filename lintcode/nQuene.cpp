class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<vector<string>> results;
        if (n <= 0) {
            return results;
        }
        
        // cols[i] means row i，Q‘s col index
        vector<int> cols;
        dfs(n, results, cols);
        return results;
    }
    
private:
    void dfs(int n, vector<vector<string>> &results, vector<int> cols) {
        if (cols.size() == n) {
            results.push_back(drawChessborad(cols));
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!isValid(cols, i)) {
                continue;
            }
            
            cols.push_back(i);
            dfs(n, results, cols);
            cols.pop_back();
        }
    }
    
    //添加皇后进来的先后次序就是行数，所以行数不需要比较，
    //因而函数中只有三个条件需要比较，列和两条斜线的比较
    bool isValid(vector<int>& cols, int col) {
        int row = cols.size();
        for (int i = 0; i < cols.size(); i++) {
            // col
            if (cols[i] == col) {
                return false;
            }

            if (i+cols[i] == row+col) {
                return false;
            }            
            
            if (i-cols[i] == row-col) {
                return false;
            } 
        }
        return true;
    }
    
    vector<string> drawChessborad(vector<int> &cols) {
        vector<string> result;
        for (int i = 0; i < cols.size(); i++) {
            string temp(cols.size(), '.');
            temp[cols[i]] = 'Q';
            result.push_back(temp);
        }
        return result;
    }
};