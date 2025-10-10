class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(),maxi = INT_MIN;
        vector<int> dp(n,0);
        for(int i=0;i<k;i++){
            dp[i] = energy[i];
        }
        for(int i = k; i < n; i++){
            dp[i] = max(energy[i],dp[i-k]+energy[i]);
        }
        for(int i = n-1;i>(n-k-1);i--){
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};