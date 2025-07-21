class Solution {
public:
    bool mono(vector<int> b,int m,int k,int mid){
        int c=0;
        for(auto &i:b){
            i = i>mid?0:1;
        }
        for(auto &i:b){
            if(i==1){
                c++;
            }
            if(i==0){
                c=0;
            }
            if(c==k){
                m--;
                c=0;
            }
            if(m==0)break;
        }
        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*1LL*k>bloomDay.size())return -1;
        int l = 1, r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l<r){
            int mid = l + (r-l)/2;
            mono(bloomDay,m,k,mid)==true?r = mid:l=mid+1;
        }
        return l;
    }
};