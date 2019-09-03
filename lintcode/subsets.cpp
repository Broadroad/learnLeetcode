#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>       
using namespace std;

class Solution {
private:
    int numberOfTrailingZeros(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (flag & n) {
                break;
            }
            count++;
            flag = flag << 1;
        }
        return count;
    }

public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > results;
        if (nums.size() == 0) {
            vector<int> result;
            results.push_back(result);
            return results;
        }
        
        sort(nums.begin(), nums.end());
        int elem_num = nums.size();
        
        int subset_num = pow (2, elem_num);
        for (int i = 0; i < subset_num; i++) {
            vector<int> result;
            int tmp = i;
            int j = 0;
            //cout << " i is " << i << endl;
            while (tmp != 0) {
                j++;
                int index = numberOfTrailingZeros(tmp);
                result.push_back(nums[index]);
                
                int t = (1 << index);
                //cout << "j is " << j << ", index is " << index << ", tmp is " << tmp << ", 1 << index is " << t << ", after xor tmp is ";
                tmp &= ~(1<<index);
                //tmp ^= (1 << index);
                //cout << tmp << endl;
            }

            results.push_back(result);
        }
        return results;
    }

/*
class Solution {
 private:
    void helper(vector<vector<int> > &results,
                vector<int> &subset,
                vector<int> &nums,
                int start) {
        results.push_back(subset);
        
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }
    
 public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > results;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        helper(results, subset, nums, 0);

        return results;
    }
};*/
};



// int main() {
//     Solution s;
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     auto r = s.subsets(nums);
//     for (size_t i = 0; i < r.size(); i++)
//     {
//         for (size_t j = 0; j < r[i].size(); j++) {
//             cout << r[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }