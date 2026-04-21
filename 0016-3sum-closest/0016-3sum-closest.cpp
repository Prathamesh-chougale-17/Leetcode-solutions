class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX,sol=0;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int x = nums[i] + nums[j] + nums[k];
                if(mini>abs(target-x)){
                    sol = x;
                    mini = abs(target-x);
                }
                if(x>target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return sol;
    }
};