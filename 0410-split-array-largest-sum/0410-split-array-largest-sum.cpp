class Solution {
public:
    bool ms(vector<int> &num,int d,int k){
        int sumi=0,maxi = 0,dk;
        for(auto &i:num){
            if((sumi+i)>d){
                // maxi = max(maxi,sumi);
                dk++;
                if(i>d){
                    // maxi = max(maxi,i);
                    sumi = 0;
                    dk++;
                }else{
                    sumi = i;
                }
            }else{
                sumi+=i;
            }
            if(dk>=k)return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        while(l<r){
            int mid = l + (r-l)/2;
            cout<<l<<' '<<mid<<' '<<r<<endl;
            if(ms(nums,mid,k)){ l = mid + 1;}
            else{ r = mid;}
        }
        return l;
    }
};