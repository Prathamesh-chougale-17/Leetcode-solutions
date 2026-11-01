class Solution {
    public int minOperations(int[] nums, int[] locked, int k) {
        int n = nums.length;
        while(n>0 && nums[n-1]==n){
            n--;
        }
        if(n<1)return 0;
        int i=0, j = 0, l = 0, s = 0;
        while(i<n-1){
            if(nums[i]==i+1){
                i++;
            }else{
                if(locked[i]==1){
                    locked[i]=0;
                    l++;
                    if(l>k)return -1;
                }
                for(j=n-1;j>i;j--){
                    if(nums[j]==(i+1)){
                        if(locked[j]==1){
                            locked[j]=0;
                            l++;
                            if(l>k)return -1;
                        }
                        // Arrays.swap(nums[j],nums[j-1]);
                        int temp = nums[j];
                        nums[j] = nums[j-1];
                        nums[j-1] = temp;
                        s++;
                    }
                }
            }
        }
        return l + s;
    }
}