class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int sol = -1;
        int n = nums.size();
        vector<int> premax,suffmin;
        int pm = nums[0],sm = nums[n-1];
        for(int i=0;i<n;i++){
            pm = max(pm,nums[i]);
            premax.push_back(pm);
            sm = min(sm,nums[n-i-1]);
            suffmin.push_back(sm);
        }
        int kt = premax[0]-suffmin[n-1];
        for(int i=0;i<n;i++){
            kt = min(kt,premax[i]-suffmin[n-1-i]);
            cout<<kt<<endl;
            if(kt<=k){
                // sol = i;
                // k = kt-1;
                return i;
            }
        }
        return sol;
    }
};

// 6 6 6
// 1 1 4