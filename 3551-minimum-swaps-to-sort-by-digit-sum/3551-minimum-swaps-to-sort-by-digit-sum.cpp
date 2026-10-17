class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            um[nums[i]]=i;
        }

        auto digitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int sa = digitSum(a), sb = digitSum(b);
            if (sa == sb) return a < b;
            return sa < sb;
        });

        vector<int> find;
        for(auto &i:nums){
            find.push_back(um[i]);
        }

        int x = 0,sol = 0;
        while(x<(n+1/2)){
            if(x!=find[x]){
                sol++;
                swap(find[x],find[find[x]]);
            }else{
                x++;
            }
        }
        return sol;
    }
};