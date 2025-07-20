class Solution {
public:
    bool mono(vector<int> &p,int k,int h){
        int s = p.size();
        for(int i=0;i<s;i++){
            h -= (1 + (p[i]-1)/k);
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        while(l<r){
            int mid = l + (r-l)/2;
            cout<<l<<" "<<mid<<" "<<r<<endl;
            if(mono(piles,mid,h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};