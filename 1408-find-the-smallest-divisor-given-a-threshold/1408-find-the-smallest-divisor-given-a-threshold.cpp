class Solution {
public:
    bool mono(vector<int> &nums,int t, int d){
        int tt = 0;
        for(auto &i:nums){
            tt += i/d;
            if(i%d!=0)tt++;
        }
        return tt<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int l = 1, r = *max_element(nums.begin(),nums.end());
        while(l<r){
            int mid = l + (r-l)/2;
            mono(nums,t,mid)==true?r = mid:l=mid+1;
        }
        return l;
    }
};