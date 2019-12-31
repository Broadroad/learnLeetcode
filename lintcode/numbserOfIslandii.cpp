class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int numberOfIsland = 0;
        int islandId = 0;
        unordered_map<int, int> index2id;
        vector<int> ans;
        if (m*n == 0) {
            return ans;
        }

        for (auto position: positions) {
            int r = position[0];
            int c = position[1];

            int index = r * n + c;
            unordered_set<int> overlap;
            if (index2id.count(index)) {
                ans.push_back(numberOfIsland);
                continue;
            }
            if (r - 1 >= 0 && index2id.count((r-1) * n + c)) overlap.insert(index2id[(r-1) * n + c]);
            if (r + 1 < m && index2id.count((r+1) * n + c)) overlap.insert(index2id[(r+1) * n + c]);
            if (c - 1 >= 0 && index2id.count(r * n + c - 1)) overlap.insert(index2id[r * n + c - 1]);
            if (c + 1 < n && index2id.count(r * n + c + 1)) overlap.insert(index2id[r * n + c + 1]);

            if (overlap.size() == 0) {
                index2id[index] = islandId++;
                ++numberOfIsland;
            } else if (overlap.size() == 1) {
                auto it = overlap.begin();
                index2id[r*n+c] = *it;
            } else {
                auto it = overlap.begin();
                for (auto &kv : index2id) {
                    if (overlap.count(kv.second)) {
                        kv.second = *it;
                    }
                }
                index2id[index] = *it;
                numberOfIsland -= (overlap.size() - 1);
            }
            ans.push_back(numberOfIsland);
        }
        return ans;
    }
};