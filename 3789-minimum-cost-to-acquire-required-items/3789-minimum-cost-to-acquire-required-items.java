class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1>need2){
            return minimumCost(cost2,cost1,costBoth,need2,need1);
        }
        return Math.min((long)costBoth*need1+(long)Math.min(costBoth,cost2)*(need2-need1),(long)Math.min(costBoth,cost1)*need1+(long)Math.min(costBoth,cost2)*need2);
        
    }
}