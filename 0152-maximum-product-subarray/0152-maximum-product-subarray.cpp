class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = 1,maxi = nums[0],f = 0;
        bool first = true;
       for(int &i:nums){
            if(i==0){
                x = 1;
            }else{
                x*=i;
                i = x;
            }
            cout<<i<<"  ";
       }

       for(int &i:nums){
            if(i<0 && first){
                f = i;
                first = false;
            }else if(i<0 && !first){
                maxi = max((i/f),maxi);
            }else if(i==0){
                maxi = max(i,maxi);
                first = true;
            }
            else{
                maxi = max(i,maxi);
            }
       }

       return maxi;
    }
};