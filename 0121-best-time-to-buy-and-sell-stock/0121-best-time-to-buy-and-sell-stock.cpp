class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0],maxi{0};
        for(int i=0;i<prices.size();i++){
            if(low>prices[i]){
                low = prices[i];
            }
            maxi = max(maxi,prices[i]-low);
        }
        return maxi;
    }
};