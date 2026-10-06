class Solution {
public:
    int msi(vector<int> &weights,int d,int k){
        int x = 0,dk = 0;
        int maxi = 0;
        for(int i=0;i<weights.size();i++){
            if((x+weights[i])>d){
                dk++;
                maxi = max(maxi,x);
                if(weights[i]>=d){
                    dk++;
                    maxi = max(maxi,weights[i]);
                    x=0;
                }else{
                    x = weights[i];
                }
            }else{
                x+=weights[i];
            }
        }
        return max(maxi,x);
    }
    bool ms(vector<int> &weights,int d,int k){
        int x = 0,dk = 0;
        for(int i=0;i<weights.size();i++){
            if((x+weights[i])>d){
                dk++;
                if(weights[i]>d){
                    dk++;
                    x=0;
                }else{
                    x = weights[i];
                }
            }else{
                x+=weights[i];
            }
            if(dk>=k)return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int k) {
        int n = weights.size();
        int s = 0;
        for(auto &i:weights)s+=i;
        int l = *max_element(weights.begin(), weights.end()), r = s;
        while(l<r){
            int mid = l + (r-l)/2;
            bool o = ms(weights,mid,k);
            // cout<<mid<<' '<<o<<endl;
            if(o){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};