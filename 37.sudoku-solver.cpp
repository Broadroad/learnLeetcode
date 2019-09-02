/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (38.50%)
 * Likes:    1037
 * Dislikes: 70
 * Total Accepted:    142.2K
 * Total Submissions: 369.3K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
private:
    bool check(vector<vector<char>>& board, int i, int j, char c) {
        for (int h = 0; h < 9; h++) {
            if (board[i][h] == c) return false;
            if (board[h][j] == c) return false;
            if (board[i-i%3+h/3][j-j%3+h%3] == c) return false;
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char>>& board, int i, int j) {
        //iterate by line
        if (i==9) return true;
        if (j==9) return solveSudokuHelper(board, i+1, 0);
        if (board[i][j] != '.') return solveSudokuHelper(board, i, j+1);

        for (char c='1'; c<='9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudokuHelper(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
};

