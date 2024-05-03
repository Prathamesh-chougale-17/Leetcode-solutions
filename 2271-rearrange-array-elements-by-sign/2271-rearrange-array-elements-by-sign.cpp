class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1,v2,v3(nums.size());
        for(auto &i:nums){
            if(i>=0){
                v1.push_back(i);
            }
            else{
                v2.push_back(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2){
                v3[i]=v2[(i-1)/2];
            }
            else{
                v3[i]=v1[i/2];
            }
        }
        return v3;
    }
};