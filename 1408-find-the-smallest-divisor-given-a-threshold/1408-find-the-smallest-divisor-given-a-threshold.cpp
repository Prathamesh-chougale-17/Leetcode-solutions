class Solution {
public:
    bool issol(vector<int> &nums,int t,int y){
        int sumi = 0;
        for(int &i:nums){
            sumi += (i-1+ y)/y;
        }
        return sumi<=t;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int maxi = *max_element(nums.begin(),nums.end());
        int i = 1, j = maxi,sol=1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(issol(nums,t,mid)){
                sol = mid;
                j = mid - 1;
            }else{
                i = mid + 1;
                cout<<i<<endl;
            }
        }
        return sol;
    }
};