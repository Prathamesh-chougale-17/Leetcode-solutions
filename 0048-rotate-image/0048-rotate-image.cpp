class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(), a = 0, b = n - 1,mid = n/2;
        while(b>=mid){
            for(int i=a;i<b;i++){
                int tmp = mat[i][b];
                mat[i][b]=mat[a][i];
                mat[a][i] = mat[b-i+a][a];
                mat[b-i+a][a] = mat[b][b-i+a];
                mat[b][b-i+a]=tmp;
            }
            a++;
            b--;
        }

    }
};