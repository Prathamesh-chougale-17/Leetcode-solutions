class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vs;
        for(int i=1;i<=n;i++){
            vs.push_back(to_string(i));
        }
        sort(vs.begin(),vs.end());
        vector<int> ans;
        for(auto &i:vs){
            ans.push_back(stoi(i));
        }
        return ans;
    }
};