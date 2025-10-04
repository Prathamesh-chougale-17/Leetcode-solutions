class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0, y = 0,a = matrix.size(), b = matrix[0].size();
        vector<int> ans;
        while(x<a && y<b){
            for(int i=y;i<b;i++){
                ans.push_back(matrix[x][i]);
            }
            x++;
            for(int i=x;i<a;i++){
                ans.push_back(matrix[i][b-1]);
            }
            b--;
            if(x<a){
                for(int i=b-1;i>=y;i--){
                    ans.push_back(matrix[a-1][i]);
                }
                a--;
            }
            if(y<b){
                for(int i=a-1;i>=x;i--){
                    ans.push_back(matrix[i][y]);
                }
                y++;
            }

        }
        return ans;
    }
};