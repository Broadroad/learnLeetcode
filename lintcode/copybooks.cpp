class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    // binary solution 
    int copyBooks(vector<int> &pages, int k) {
        int l = 0, r = INT_MAX;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (check(pages, mid, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check(pages, l, k)) {
            return l;
        }
        
        return r;
    }
    
private:
    bool check(vector<int> &pages, int limit, int k) {
        // give the limit from start to end
        int left = 0;
        int num = 0;
        for (int page : pages) {
            if (page > limit) {
                return false;
            }
            
            if (page > left) {
                left = limit;
                num++;
            }
            left -= page;
        }
        return num <= k;
    }
};