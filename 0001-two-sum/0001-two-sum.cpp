class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        int arr[n];
        transform(nums.begin(),nums.end(),arr,[](const int & x){return x;});
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(arr[i]+arr[j]==target)
                    return {i,j};
        return {0};
    }
};