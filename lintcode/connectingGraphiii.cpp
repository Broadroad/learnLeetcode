class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    int count = 0;
    vector<int> parent;
    vector<int> rank;
    int n;
     ConnectingGraph3(int n) {
        // initialize your data structure here.
        this->n = n;
        this->count = n;
        parent.resize(n+1);
        rank.resize(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    void connect(int a, int b) {
        // write your code here
        int parent_a = find(a);
        int parent_b = find(b);
        if (parent_a == parent_b) return;
        if (rank[parent_a] < rank[parent_b]) {
            parent[parent_b] = parent_a;
            rank[parent_a] += rank[parent_b];
        } else {
            parent[parent_a] = parent_b;
            rank[parent_b] += rank[parent_a];
        }
        count--;
    }

    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

    /**
     * @return: An integer
     */
    int query() {
        // write your code here
        return count;
    }
};