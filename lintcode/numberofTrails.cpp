#include <iostream>
class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    int trailingZeros(int n) {
        // write your code here, try to do it without arithmetic operators.
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            std::cout << flag << std::endl;
            if (flag & n) {
                std::cout << "sdaf" << std::endl;
                break;
            }
            
            count++;
            flag = flag << 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    std::cout << s.trailingZeros(11) << std::endl;

}