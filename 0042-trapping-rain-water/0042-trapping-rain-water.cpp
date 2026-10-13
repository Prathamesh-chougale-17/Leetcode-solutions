class Solution {
public:
    int trap(vector<int>& height) {
        int s = 0;
        int nn = 0;
        int t=0;
        int n = height.size();
        int maxi = height[0];
        for(int i=1;i<n;i++){
            if(height[s]>height[i]){
                nn+=height[i];
            }else{
                t+=(min(height[s],height[i])*(i-s-1)-nn);
                s = i;
                nn = 0;
                maxi = max(maxi,height[i]);
                // cout<<"hello"<<endl;
            }
            // cout<<t<<' '<<nn<<endl;
        }
        nn=0;
        s = n-1;
        if(height[s]==maxi)return t;
        for(int i=n-2;i>=0;i--){
            if(height[s]>height[i]){
                nn+=height[i];
            }else{
                t+=(min(height[s],height[i])*(s-i-1)-nn);
                s = i;
                nn = 0;
                if(maxi == height[i]) return t;
            }
        }
        return t;
    }
};