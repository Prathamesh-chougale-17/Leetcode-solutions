class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        int maxi = 1;
        int[] tmp = new int[n];
        int[] count = new int[n];
        Arrays.fill(tmp,1);
        Arrays.fill(count,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    // tmp[i] = Math.max(tmp[i],1+tmp[j]);
                    if(tmp[i]<1+tmp[j]){
                        tmp[i] = 1 + tmp[j];
                        count[i] = count[j];
                    }else if(tmp[i]==1+tmp[j]){
                        count[i] += count[j];
                    }
                }
            }
            maxi = Math.max(maxi,tmp[i]);
            System.out.print(maxi + " ");
        }
        int sol = 0;
        for(int i=0;i<n;i++){
            if(tmp[i]==maxi){
                sol+=count[i];
            }
        }
        return sol;
    }
}