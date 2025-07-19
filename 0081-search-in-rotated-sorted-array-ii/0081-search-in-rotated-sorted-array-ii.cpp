class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return true;
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
                continue;
            }
            // Right half is sorted
            if (nums[mid] <= nums[r]) {
                (nums[mid] < target && target <= nums[r]) ? l = mid + 1 : r = mid - 1;
            }
            // Left half is sorted
            else {
                (nums[l] <= target && target < nums[mid]) ? r = mid - 1 : l = mid + 1;
            }
        }
        return false;
    }
};
