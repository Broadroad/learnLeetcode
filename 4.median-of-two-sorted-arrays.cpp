/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.63%)
 * Total Accepted:    394.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        int m = nums1.size();
        int n = nums2.size();

        if (m > n) { // to ensure m<=n
            vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }

          //only one number print it directly
        if (n == 0)
            return 0.0;
        if (m == 0) {
            if (n % 2 != 0)
                return nums2[n / 2] * 1.0;
            else {
                return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
            }

        }

        int odd = (m + n) % 2;
        
        int imin = 0, imax = m, halfLen = (m + n + 1) / 2;


        // divided 2 arrays into 4 arrays
        //          left_part          |        right_part
        // A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
        // B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
        // ensure that A[i-1]<B[j] && B[j-1] < A[i]
        // then median= (max(left_part)+min(right_part))/2
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            cout << i << " " << j << endl;

            if (i < imax && nums2[j-1] > nums1[i]) {
                imin = i + 1;
            } else if (nums1[i-1] > nums2[j]){
                imax = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j-1];
                }
                else if (j == 0) { maxLeft = nums1[i-1]; }
                else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                if (odd == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

int main() {
    vector<int> a,b ;
    a.push_back(3);
    b.push_back(-2);
    b.push_back(-1);

    Solution s;
    cout << s.findMedianSortedArrays(a,b) << endl;
}

