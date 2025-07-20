class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi = nums[0],count = 1,n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==maxi){
                count++;
            }else{
                count--;
                cout<<count<<endl;
                if(count<1){
                    maxi = nums[i];
                    count = 1;
                }
            }
        }
        return maxi;
    }
};