class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int n=queries.size();
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
        int sol=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                sol^=arr[j];
            }
            ans.push_back(sol);

        }
        return ans;
        
    }
};