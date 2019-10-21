/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.62%)
 * Likes:    2310
 * Dislikes: 111
 * Total Accepted:    270.8K
 * Total Submissions: 683.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // write your code here
        int number = 0;
        vector<unordered_multiset<int>> edges(numCourses);
        //入度
        vector<int> d(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].insert(prerequisites[i][0]);
            d[prerequisites[i][0]]++;            
        }

        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (d[i] == 0) {
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            number++;
            for (auto it = edges[v].begin(); it != edges[v].end(); it++) {
                d[*it]--;
                if (d[*it] == 0) {
                    Q.push(*it);
                }
            }
        }
        return number == numCourses;
    }
};
// @lc code=end

