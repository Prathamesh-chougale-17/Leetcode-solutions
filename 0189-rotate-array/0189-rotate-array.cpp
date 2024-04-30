class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nv(n);
        for(int i=0;i<n;i++){
            nv[i]=nums[(n+i-k%n)%n];
        }
        nums = nv;
    }
};