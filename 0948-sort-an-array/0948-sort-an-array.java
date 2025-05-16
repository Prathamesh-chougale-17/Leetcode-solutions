class Solution {
    public int[] sortArray(int[] nums) {
        if (nums.length == 0) return nums;

        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        
        // Find min and max
        for (int num : nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }

        int range = max - min + 1;
        int[] freq = new int[range];

        // Count frequency
        for (int num : nums) {
            freq[num - min]++;
        }

        // Fill sorted result
        int index = 0;
        for (int i = 0; i < range; i++) {
            while (freq[i]-- > 0) {
                nums[index++] = i + min;
            }
        }

        return nums;
    }
}
