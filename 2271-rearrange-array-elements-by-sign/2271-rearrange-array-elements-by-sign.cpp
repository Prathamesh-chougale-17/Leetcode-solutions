class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // if we put positive number to the odd place we get our vector
        int k=0,j=1,n=nums.size();
        vector<int> ans(n);
        for(int &i:nums){
            if(i<0){
                ans[j]=i;
                j+=2;
            }
            else{
                ans[k]=i;
                k+=2;
            }
        }
        return ans;
    }
};