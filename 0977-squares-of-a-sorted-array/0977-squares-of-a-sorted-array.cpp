class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = -1,r = 0,n = nums.size();
        vector<int> ans;
        if(nums[0]>=0)
        {
            for(int i=0;i<n;i++){
                ans.push_back(nums[i]*nums[i]);
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                r = i;
                l = i-1;
                break;
            }
        }
        if(l==-1){
            for(int i=n-1;i>=0;i--){
                ans.push_back(nums[i]*nums[i]);
            }
            return ans;
        }
        while(l>=0 && r<n){
            int ls = nums[l]*nums[l],rs = nums[r]*nums[r];
            if(ls>rs){
                ans.push_back(rs);
                r++;
            }else{
                ans.push_back(ls);
                l--;
            }
        }
        while(l>=0){
            int ls = nums[l]*nums[l];
            ans.push_back(ls);
            l--;
        }
        while(r<n){
            int rs = nums[r]*nums[r];
            ans.push_back(rs);
            r++;
        }

        return ans;
    }
};