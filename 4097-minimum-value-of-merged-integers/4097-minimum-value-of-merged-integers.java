class Solution {
    public int minMergedInteger(int[] nums) {
        int mini = Integer.MAX_VALUE;
        for(int i=1;i<nums.length;i+=2){
            mini = Math.min(mini,Integer.parseInt(Integer.toString(nums[i-1])+Integer.toString(nums[i])));
        }
        return mini;
    }
}