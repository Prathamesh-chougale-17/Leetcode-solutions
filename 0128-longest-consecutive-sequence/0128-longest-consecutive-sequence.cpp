class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int p = nums[0],maxi=0,count=1;
        for(auto &i:nums){
            if(p!=i){
                if(p==(i-1)){
                    count++;
                    cout<<i<<endl;
                }
                else{ count = 1;}
                p=i;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};