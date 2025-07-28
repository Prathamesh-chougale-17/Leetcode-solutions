class Solution {
public:
    void back(unordered_map<int,int> &um,int o,int i,int n,vector<int> &nums){
        if(i==n){
            um[o]++;
            return;
        }
        back(um,o|nums[i],i+1,n,nums);
        back(um,o,i+1,n,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int> um;
        back(um,0,0,nums.size(),nums);
        int maxi = 0;
        for(auto &i:um){
            maxi = max(maxi,i.first);
        }
        // cout<<maxi;
        return um[maxi];
    }
};