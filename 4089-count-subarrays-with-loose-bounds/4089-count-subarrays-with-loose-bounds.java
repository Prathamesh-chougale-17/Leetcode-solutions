class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long p = 0,ans = 0;
        for(int i:nums){
            if(i>=minK && i<=maxK){
                p++;
            }else{
                ans+=(p*(p+1)/2);
                p=0;
            }
        }
        ans+=(p*(p+1)/2);
        return ans;
    }
}