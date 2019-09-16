#include <iostream>
#include <climits>

/*
    weight = {2, 2, 4, 6, 3}
    n = 5 
    w = 9

    Q: how to get the most weight which is smaller than 9
*/

class Solution {
private:
    int weight[5] = {2, 2, 4, 6, 3};
    int n = 5;
    int w = 9;
    bool mem[5][10]  = {{0}};
public:
    int maxW = INT_MIN;
    // 回溯
    void f(int i, int cw) {
        if (cw == w || i == n) {
            if (cw > maxW) {
                maxW = cw;
            }
            return;
        }

        f(i+1, cw);
        if (cw + weight[i] <= w) {
            f(i+1, cw+weight[i]);
        }
    }

    // 回溯+记忆化搜索
    void f2(int i, int cw) {
        if (cw == w || i == n) {
            if (cw > maxW) {
                maxW = cw;
            }
            return;
        }

        if (mem[i][cw]) return;
        f(i+1, cw);
        if (cw + weight[i] <= w) {
            f(i+1, cw+weight[i]);
        }
    }

    // dp with 2d arrays
    int f3(int n, int w) {
        bool states[n][w+1];
        states[0][0] = true;
        if (weight[0] <= w) {
            states[0][weight[0]] = true;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                if (states[i-1][j] == true) {
                    states[i][j] = states[i-1][j];
                }
            }

            for (int j = 0; j <= w-weight[i]; j++) {
                if (states[i-1][j] == true) {
                    states[i][j+weight[i]] = true;
                }
            }
        }

        for (int i = w; i >= 0; i--) {
            if (states[n-1][i] == true) {
                return i;
            }
        }

        return 0;
    }

    // dp with 1d array
    int f4(int n, int w) {
        int states[w+1];
        states[0] = true;

        if (weight[0] <= w) {
            states[weight[0]] = true;
        }

        
        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = w - weight[i]; j >= 0; j--) {
                if (states[j] == true) {
                    std::cout << i << " " << j << " " << states[j] << std::endl;
                    states[j+weight[i]] = true;
                    count++;
                }
            }
        }
        std::cout << count << std::endl;

        for (int i = w; i >= 0; i--) {
            if (states[i] == true) {
                return i;
            }
        }
        return 0;
    }
    
     // dp with 1d array
    int f5(int n, int w) {
        int states[w+1];
        states[0] = true;

        if (weight[0] <= w) {
            states[weight[0]] = true;
        }

        
        int count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= w; j++) {
                if (states[j] == true) {
                    std::cout << i << " " << j << " " << states[j] << std::endl;
                    states[j+weight[i]] = true;
                    count++;
                }
            }
        }
        std::cout << count << std::endl;

        for (int i = w; i >= 0; i--) {
            if (states[i] == true) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    std::cout << s.f4(5, 9) << std::endl;
    
    std::cout << "f5: " << std::endl;
    std::cout << s.f5(5, 9) << std::endl;
    //std::cout << s.maxW << std::endl;
}