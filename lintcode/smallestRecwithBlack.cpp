class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) {
            return 0;
        }
        
        int n = image.size();
        int m = image[0].size();
        
        int left = findLeft(image, 0, y);
        int right = findRight(image, y, m - 1);
        int top = findTop(image, 0, x);
        int bottom = findBottom(image, x, n - 1);
        return (right - left + 1) * (bottom - top + 1);
    }
    
private:
    int findLeft(vector<vector<char>> &image, int start, int end) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isEmptyCol(image, mid)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (isEmptyCol(image, start)) {
            return end;
        }
        
        return start;
    }
    
    int findRight(vector<vector<char>> &image, int start, int end) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isEmptyCol(image, mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (isEmptyCol(image, end)) {
            return start;
        }
        
        return end;
    }
    
    int findTop(vector<vector<char>> &image, int start, int end) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isEmptyRow(image, mid)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (isEmptyRow(image, start)) {
            return end;
        }
        
        return start;
    }
    
    int findBottom(vector<vector<char>> &image, int start, int end) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isEmptyRow(image, mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (isEmptyRow(image, end)) {
            return start;
        }
        return end;
    }
    
    bool isEmptyCol(vector<vector<char>> &image, int col) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][col] == '1') {
                return false;
            }
        }
        return true;
    }
    
    bool isEmptyRow(vector<vector<char>> &image, int row) {
        for (int i = 0; i < image[0].size(); i++) {
            if (image[row][i] == '1') {
                return false;
            }
        }
        return true;
    }
};