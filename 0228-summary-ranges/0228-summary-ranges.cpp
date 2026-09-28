class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n<1)return {};
        int s = nums[0];
        vector<string> sol;
        string sn;
        for(int i=1;i<n;i++){
            if(nums[i]!=(nums[i-1]+1)){
                if(s==nums[i-1]){
                    sn = to_string(s);
                }else{
                    sn = to_string(s)+"->"+to_string(nums[i-1]);
                }
                sol.push_back(sn);
                s = nums[i];
            }
        }
        if(s==nums[n-1]){
                sn = to_string(s);
        }else{
                sn = to_string(s)+"->"+to_string(nums[n-1]);
        }
        sol.push_back(sn);
        return sol;
    }
};