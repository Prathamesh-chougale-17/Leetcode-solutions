class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j = grid.size()-1,ans{0};
        for(int i=0;i<grid[0].size();i++){
            if(j>=0 && grid[j][i]<0){
                ans += grid[0].size()-i;
                // cout<<ans<<endl;
                j--;i--;
            }
        }
        return ans;
    }
};