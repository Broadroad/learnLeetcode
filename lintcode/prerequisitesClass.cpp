class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        int number = 0;
        vector<unordered_multiset<int>> edges(numCourses);
        //入度
        vector<int> d(numCourses, 0);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            auto edge = prerequisites[i];
            edges[edge.second].insert(edge.first);
            d[edge.first]++;
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