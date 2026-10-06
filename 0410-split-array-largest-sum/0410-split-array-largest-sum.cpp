class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int parts = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x > maxSum) {
                parts++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (canSplit(nums, mid, k)) {
                // mid is possible, try smaller
                r = mid;
            } else {
                // mid is too small
                l = mid + 1;
            }
        }

        return l;
    }
};