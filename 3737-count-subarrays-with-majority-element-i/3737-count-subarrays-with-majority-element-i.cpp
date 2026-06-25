class Solution {
public:
    int countTarget(vector<int>& nums, int target,int i,int j){
        int sumi = 0;
        for(int k = i;k<=j;k++){
            if(target==nums[k])sumi++;
        }
        return sumi;
    }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int maxi = 0;
        // prefix sum
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            int ct = 0;
            for(int j=i;j<n;j++){
                if(target==nums[j])ct++;
                int x = ct;
                if(x>((j-i+1)/2)){
                    maxi++;
                }
            }
        }

        return maxi;
    }
};

// i->j how many target are there-> O(1)


// [1,3,2,4,2,2,2,2,4]
// [0,0,1,0,2,3,4,5,0]
// [0,1,2,2]

// [1,2,2,3] -> [1],[2],[2],[3],[1,2],[2,3],[2,2],[2,2,3],[1,2,2],[1,2,2,3]

// [2,2],[2,2,3],[1,2,2],[2],[2]

// 10^3 = n3 = 10^6