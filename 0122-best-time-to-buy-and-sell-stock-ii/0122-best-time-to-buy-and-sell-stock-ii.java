class Solution {
    public int maxProfit(int[] prices) {
        int p = 0;
        int min = prices[0];
        for(int i=1;i<prices.length;i++){
            // min = Math.min(min,i);
            p += Math.max(0,prices[i]-prices[i-1]);
        }
        return p;
    }
}