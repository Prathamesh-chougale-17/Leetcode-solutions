class Solution {
    public int countDominantElements(int[] nums) {
        int n = nums.length;
        if(n==1)return 1;
        int sol = 0;
        if(nums[1]<=nums[0])
            sol += 1;
        if(nums[n-1]>=nums[n-2])
            sol += 1;

        for(int i=1;i<(n-1);i++){
            if(nums[i]>=(nums[i-1]+nums[i+1]+1)/2)
                sol+=1;
        }
        return sol;
    }
}