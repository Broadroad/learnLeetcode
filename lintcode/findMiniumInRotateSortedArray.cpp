class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        int start = 0, end = n - 1;
        int target = nums[end];
        while (start+1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        return min(nums[start], nums[end]);
    }
};