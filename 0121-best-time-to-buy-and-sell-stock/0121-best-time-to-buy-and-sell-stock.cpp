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
        int lsf = INT_MAX;
        int op = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if(op < pist){
                op = pist;
            }
        }
        return op;
        
    }
};