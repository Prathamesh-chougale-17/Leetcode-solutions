class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int x = 1,y = 1,maxi = 1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                x++;
                y=1;
            }else if(nums[i]>nums[i-1]){
                y++;
                x=1;
            }else{
                x=1;
                y=1;
            }
            maxi = Math.max(maxi,Math.max(x,y));
        }
        return maxi;
    }
}