class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                start = mid;
            }
            else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else {
                return nums[mid];
            }
        }
        return max(nums[start], nums[end]);
    }
};