class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int x = target.size();
        int z = target[x-1];
        vector<string> sol;
        int pt = 0;
        for(int i = 0;i < z;i++){
            sol.push_back({"Push"});
            if(pt<target.size() && target[pt]==(i+1)){
                pt++;
            }else{
                sol.push_back({"Pop"});
            }
        }
        return sol;
    }
};