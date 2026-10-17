class Solution {
    private int netSum(int a){
        int x = 0;
        while(a>0){
            x+=a%10;
            a/=10;
        }
        return x;
    }
   
    public int minSwaps(int[] nums) {
        List<Integer> ind = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            ind.add(i);
        }

        ind.sort((x,y)->{
            int a = netSum(nums[x]);
            int b = netSum(nums[y]);
            if(a==b)return Integer.compare(nums[x],nums[y]);
            return Integer.compare(a,b);
        });

        int x = 0, sol = 0;
        while(x<nums.length){
            if(x!=ind.get(x)){
                sol++;
                // int targetIndex = ind.get(x);
                Collections.swap(ind,x,ind.get(x));
            }
            else{
                x++;
            }
        }
        return sol;
    }
}