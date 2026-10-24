class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        if(n==1)return 0;
        int sol = 0,pos0 = 0, posn = 0;
        boolean des = ((nums[1] - nums[0])==1 || (nums[1] - nums[0])==(1-n))?false:true;
        for(int i=1;i<n;i++){
            if(Math.abs(nums[i]-nums[i-1])!=1 && Math.abs(nums[i]-nums[i-1])!=(n-1)){
                return -1;
            }
            if(nums[i]==0)pos0=i;
            if(nums[i]==(n-1))posn = i;
        }
        if(des){
            sol = 1 + Math.min(posn,n-1-pos0);
        }else{
            sol = Math.min(pos0,n+1-posn);
        }
        return sol;
    }
}

// 