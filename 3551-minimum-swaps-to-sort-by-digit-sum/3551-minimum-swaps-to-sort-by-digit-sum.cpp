class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> find;
        for(int i=0;i<n;i++){
            find.push_back(i);
        }

        auto digitSum = [](int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        sort(find.begin(), find.end(), [&](int a, int b) {
            int sa = digitSum(nums[a]), sb = digitSum(nums[b]);
            if (sa == sb) return nums[a] < nums[b];
            return sa < sb;
        });


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

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();