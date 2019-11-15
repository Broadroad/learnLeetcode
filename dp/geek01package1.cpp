#include <iostream>
#include <climits>

/*
    weight = {2, 2, 4, 6, 3}
    n = 5 
    w = 9
    values = {3, 4, 8, 9, 6};
    Q: how to get the most weight which is smaller than 9
*/

class Solution
{
private:
    int weight[5] = {2, 2, 4, 6, 3};
    int values[5] = {3, 4, 8, 9, 6};
    int n = 5;
    int w = 9;
    bool mem[5][10] = {{0}};

public:
    int maxV = INT_MIN;
    void f(int i, int cw, int cv)
    {
        if (cw == w || i == n)
        {
            if (cv > maxV)
            {
                maxV = cv;
            }
            return;
        }

        f(i + 1, cw, cv);
        if (cw + weight[i] < w)
        {
            f(i + 1, cw + weight[i], cv + values[i]);
        }
    }

    int f1(int n, int w)
    {
        int states[n][w + 1];
        memset(states, -1, sizeof(dp));
        /* initial
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w + 1; j++) {
                states[i][j] = -1;
            }
        } */
        states[0][0] = 0;
        if (weight[0] <= w)
        {
            states[0][weight[0]] = values[0];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (states[i - 1][j] >= 0)
                {
                    states[i][j] = states[i - 1][j];
                }
            }

            for (int j = 0; j <= w - weight[i]; ++j)
            { // 选择第 i 个物品
                if (states[i - 1][j] >= 0)
                {
                    int v = states[i - 1][j] + value[i];
                    if (v > states[i][j + weight[i]])
                    {
                        states[i][j + weight[i]] = v;
                    }
                }
            }
        }

        // 找出最大值
        int maxvalue = -1;
        for (int j = 0; j <= w; ++j)
        {
            if (states[n - 1][j] > maxvalue)
                maxvalue = states[n - 1][j];
        }
        return maxvalue;
    }
};

int main()
{
    Solution s;
    s.f(0, 0, 0);
    std::cout << s.maxV << std::endl;
    std::cout << s.f1(5, 9) << std::endl;
}