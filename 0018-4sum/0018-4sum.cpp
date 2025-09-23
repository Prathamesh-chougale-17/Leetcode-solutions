class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<vector<int>> sol;
        for(int x = 0;x<n-3;x++){
            while(x>0 && nums[x]==nums[x-1] && x<n-3) x++;
            for(int i=x+1;i<n-2;i++){
                while(i>x+1 && nums[i]==nums[i-1] && i<n-2){
                    i++;
                }
                int j = i+1,k = n-1;
                while(j<k){
                    long long sum = 1LL*nums[i]+1LL*nums[j]+1LL*nums[k]+1LL*nums[x];
                    if(sum==target){
                        sol.push_back({nums[x],nums[i],nums[j],nums[k]});
                        j++;k--;
                        while(j<k && nums[j]==nums[j-1])j++;
                        while(j<k && nums[k]==nums[k+1])k--;
                    }
                    else if(sum<target){
                        j++;
                    }else{
                        k--;
                    }
                }
            }
        }
        return sol;
    }
};