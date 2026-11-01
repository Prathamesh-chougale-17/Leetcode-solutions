class Solution {
    public int minMoves(int[] nums) {
        Arrays.sort(nums);
        int sol = 0, n = nums.length;
        for(int i = 1;i<n;i++){
            sol+=i*(nums[n-i]-nums[n-i-1]);
        }
        return sol;
    }
}

// 1 3 4 5
// 