class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(auto &i:nums){
            int n = sqrt(i);
            if(i==n*n)continue;
            n++;
            int sumi = i+(1!=i);
            bool ischanged = false;
            for(int j = 2;j<n;j++){
                if(i%j==0){
                    if(ischanged){
                        sumi=0;
                        break;
                    }
                    sumi+=j+i/j;
                    ischanged=true;
                }
            }
            if(ischanged)
                total+=sumi;
        }
        return total;
    }
};