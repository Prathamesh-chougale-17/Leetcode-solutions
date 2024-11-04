class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0,mini=prices[0],n=prices.size();
        for(int i=1;i<n;i++){
            mini = min(prices[i],mini);
            maxi = max(maxi,prices[i]-mini);
        }
        return maxi;
    }
};