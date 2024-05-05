class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),isdec{1},breakpoint{0};
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakpoint=i;
                isdec=0;
                break;
            }
        }
        if(!isdec){
            int jmax{INT_MAX},maxi{0},mini=nums[breakpoint],swapp{0};
            for(int i=breakpoint+1;i<n;i++){
                maxi = max(mini,nums[i]);
                // jmax = min(maxi,jmax);
                if(jmax>maxi && maxi!=mini){
                    jmax = maxi;
                    swapp = i;
                    cout<<i<<maxi<<endl;
                }
            }
            swap(nums[breakpoint],nums[swapp]);
            // cout<<*(nums.begin());
            sort(nums.begin()+breakpoint+1,nums.end());
        }
        else{
            sort(nums.begin(),nums.end());
        }
    }
};