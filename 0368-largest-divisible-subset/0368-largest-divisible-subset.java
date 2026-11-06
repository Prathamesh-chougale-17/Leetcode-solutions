class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] tmp = new int[n];
        Arrays.fill(tmp,1);
        int[] p = new int[n];
        for(int i=0;i<n;i++){
            p[i] = i;
        }
        int ls = 0,maxi = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int s = 1+tmp[j];
                if(nums[i]%nums[j]==0 && tmp[i]<s){
                    tmp[i] = s;
                    p[i] = j;
                    if(maxi<s){
                        maxi = s;
                        ls = i;
                    }
                }
            }
        }
        // for()
        List<Integer> sol = new ArrayList<>();
        // System.out.println(p[ls] + "  " + ls);
        while(p[ls]!=ls){
            sol.add(nums[ls]);
            ls = p[ls];
        }
        sol.add(nums[ls]);
        Collections.reverse(sol);
        return sol;
    }
}