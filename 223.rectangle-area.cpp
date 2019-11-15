/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    296
 * Dislikes: 575
 * Total Accepted:    94.9K
 * Total Submissions: 259.3K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * (min(C, G) - max(A, E)) × (min(D, H) - max(B, F))
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area = 0;
        if ((min(C,G) > max(A,E)) && (min (D,H) > max(B,F))) {
            area = ((min(C,G) - max(A,E)) * (min (D,H) - max(B,F)));
        }
        long area1 = (D - B) * (C - A);
        long area2 = (H - F) * (G - E);
        return (int)(area1 + area2 - area);
    }
};
// @lc code=end

