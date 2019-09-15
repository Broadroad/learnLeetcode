class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        
        int prev = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[prev] > nums[i]) {
                break;
            } else {
                prev = i;
            }
        }
        
        revert(nums, 0, prev);
        revert(nums, prev+1, nums.size()-1);
        revert(nums, 0, nums.size()-1);
        
    }
private:
    void revert(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++; right--;
        }
    }
};