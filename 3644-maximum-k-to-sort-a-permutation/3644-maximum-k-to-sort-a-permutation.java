class Solution {
    public int sortPermutation(int[] nums) {
        int k = -1;
        int i = 0,n=nums.length;
        while(i<n){
            if(nums[i]!=i){
                k = k & nums[i];
                System.out.println(k);
            }
            i++;
        }
        return Math.max(k,0);
    }
}