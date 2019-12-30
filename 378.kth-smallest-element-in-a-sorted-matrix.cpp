/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (51.67%)
 * Likes:    1658
 * Dislikes: 101
 * Total Accepted:    144.1K
 * Total Submissions: 278.9K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Node {
public:
    int x;
    int y;
    int val;
    Node(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {};
};

class cmp {
public:
    bool operator()(Node a, Node b) {
        return a.val > b.val;
    }
};
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;

        if (!m || !n || k < 0) {
            return 0;
        }

        int dx[2] = {1, 0};
        int dy[2] = {0, 1};
        priority_queue<Node, vector<Node>, cmp> pq;
        bool hash[m][n];
        memset(hash, false, sizeof(hash));
        pq.push(Node(0, 0, matrix[0][0]));
        hash[0][0] = true;
        for (int j = 1; j < k; j++) {
            Node node = pq.top();
            pq.pop();

            for (int i = 0; i < 2; i++) {
                int x = node.x + dx[i];
                int y = node.y + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && hash[x][y] == false) {
                    pq.push(Node(x, y, matrix[x][y]));
                    hash[x][y] = true;
                }
            }
        }
        return pq.top().val;
    }
};

class Solution {
public:
    // binary search
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;

        if (!m || !n || k < 0) {
            return 0;
        }

        int left = matrix[0][0], right = matrix[m-1][n-1];
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int numOflessOrEqual = getLessOrEqual(matrix, mid);
            if (numOflessOrEqual >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int getLessOrEqual(vector<vector<int>>& matrix, int num) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = m - 1;
        int j = 0;

        int ans = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= num) {
                ans += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return ans;
    }
};
// @lc code=end

