/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> result;
        if (graph.size() == 0) {
            return result;
        }
        unordered_map<DirectedGraphNode*, int> m;
        for(auto a: graph) {
            for (auto b: a.neighbors) {
                if (m.find(b) != m.end()) {
                    m[b] += 1;
                } else {
                    m[b] = 1;
                }
            }
        }

        queue<DirectedGraphNode*> Q;
        for (auto a: graph) {
            if (m.find(a) == m.end()) {
                Q.push(a);
                result.push_back(a);
            }
        }

        while(!Q.empty()) {
            DirectedGraphNode* node = Q.front();
            Q.pop();
            for (auto a: node.neighbors) {
                m[a] = m[a] - 1;
                if (m[a] == 0) {
                    result.push_back(a);
                    Q.push(a);
                }
            }
        }

        return result;
    }
};