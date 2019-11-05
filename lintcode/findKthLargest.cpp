class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if (n < 0 || n > nums.size() || nums.size() == 0) {
            return -1;
        }

        return partition(nums, 0, nums.size()-1, nums.size()-n);
    }

private:
    int partition(vector<int> &nums, int start, int end, int k) {
        if (start >= end) {
            return nums[k];
        }

        int left = start, right = end;
        int pivot = nums[(start + end) / 2];
        while (left <= right) {
            while (left <= right && nums[left] < pivot) left++;
            while (left <= right && nums[right] > pivot) right--;
            if (left <= right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left++;
                right--;
            }
        }

        if (k >= left) {
            return partition(nums, left, end, k);
        }

        if (k <= right) {
            return partition(nums, start, right, k);
        }
        return nums[k];
    }
};
