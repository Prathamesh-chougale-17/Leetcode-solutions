class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int maxi = 0, sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        maxi = sum;
        for(int i=0;i<nums.length-k;i++){
            sum = sum + nums[k+i] - nums[i];
            maxi = Math.max(maxi,sum);
        }
        return (double)maxi/k;
    }
}