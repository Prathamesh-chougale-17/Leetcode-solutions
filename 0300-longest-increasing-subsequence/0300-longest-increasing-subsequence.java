class Solution {
    // int INF = (int)1e4 + 1;
    // public int back(int[] nums,int i,int j,int[][] dp){
    //     if(i>=nums.length)return 0;
    //     if(dp[i][INF+j]!=-1)return dp[i][INF+j];
    //     int take = 0;
    //     if(j<nums[i]) take = 1 + back(nums,i+1,nums[i],dp);
    //     int notTake = back(nums,i+1,j,dp);
    //     return dp[i][INF+j] = Math.max(take,notTake);
    // }
    public int back(int[] nums,int i,int j,int[][] dp){
        if(i>=nums.length)return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int take = 0;
        if(j==-1 || nums[j]<nums[i]) take = 1 + back(nums,i+1,i,dp);
        int notTake = back(nums,i+1,j,dp);
        return dp[i][j+1] = Math.max(take,notTake);
    }
    public int lengthOfLIS(int[] nums) {
        // int[][] dp = new int[nums.length][2*INF];
        int[][] dp = new int[nums.length][nums.length+1];
        for(int i=0;i<nums.length;i++){
            Arrays.fill(dp[i],-1);
        }
        // return back(nums,0,-INF,dp);
        return back(nums,0,-1,dp);



        // greedy - not working
        // PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        // int maxi = 0;
        // for(int i:nums){
        //     while(pq.size()>0 && pq.peek()>=i){
        //         pq.poll();
        //     }
        //     pq.add(i);
        //     maxi = Math.max(maxi,pq.size());
        // }
        // return maxi;

        // List<Integer> arr = new ArrayList<>();
        // int ind = 0;
        // for(int i:nums){
        //     int n = arr.size();
        //     if(n==0 || arr.get(n-1)<i) arr.add(i);
        //     else{
        //         int ind = Collections.binarySearch(arr,i);
        //         if(ind<0){
        //             ind = -(ind+1);
        //             arr.set(ind,i);
        //         }
        //     }
        // }
        // return arr.size();
    }
}