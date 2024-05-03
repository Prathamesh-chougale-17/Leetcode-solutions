class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // map<int,int,greater<int>> m;
        // for(int i=0;i<prices.size();i++){
        //     m[prices[i]]=i;
        // }
        // auto min = min_element(prices.begin(),prices.end());
        // auto max = max_element(min,prices.end());
        // return *max-*min;
        // int diff{0};
        // for(int i=0;i<prices.size();i++){
        //     auto mini = min_element(prices.begin(),prices.end()-i);
        //     // auto maxi = max_element(mini,prices.end()-i);
        //     diff = max((prices[prices.size()-1-i]-*mini),diff);
        // }
        // return diff;

        int mini{prices[0]},profit{0},cost{0};
        for(int i=1;i<prices.size();i++){
            cost = prices[i]-mini;
            if(cost>profit) profit = cost;
            mini = min(mini,prices[i]);
        }
        return profit;
        
    }
};