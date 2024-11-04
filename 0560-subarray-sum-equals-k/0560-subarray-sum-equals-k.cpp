class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(1,0);
        int sum=0,n = nums.size(),count=0;
        for(int &i:nums){
            sum+=i;
            prefix.push_back(sum);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((prefix[j]-prefix[i])==k)count++;
            }
        }
        return count;
    }
};