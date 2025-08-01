class Solution {
public:
    int nCr(int n, int r) {
        if (r < 0 || n < 0) return 0;   // invalid case
        if (r > n) return 0;
        if (r == 0 || r == n) return 1; // base cases

        if (r > n - r) r = n - r;       // choose smaller r
        long long ans = 1;
        for (int i = 0; i < r; i++) {
            ans *= (n - i);
            ans /= (i + 1);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            for(int j = 0;j < i;j++){
                temp.push_back(nCr(i-1,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};