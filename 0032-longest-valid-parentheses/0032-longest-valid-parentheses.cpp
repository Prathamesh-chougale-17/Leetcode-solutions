class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp;
        dp.push_back(0);
        int x = 0;
        for(auto &i:s){
            if(i=='(')x++;
            else x--;
            dp.push_back(x);
        }
        int n = dp.size();
        int maxi = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                // cout<<j<<' '<<i<<endl;
                if(dp[j]<dp[i])break;
                else if(dp[j]==dp[i])maxi = max(maxi,j-i);
                else if((dp[j]-max(0,dp[i]))>=(n/2+1)){
                    // cout<<j<<' '<<i<<endl;
                    while(j<n && (dp[j]-max(0,dp[i]))>=(n/2+1)){
                        i++;
                        j++;
                    }
                    i--;
                    // cout<<dp[j]<<' '<<dp[i]<<endl;
                    break;
                }
            }
        }
        return maxi;
    }
};