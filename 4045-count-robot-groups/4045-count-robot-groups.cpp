class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int k) {
        int n = position.size();
        int g = 1;
        int ns = 0;
        int x = speed[n-1];

        for(int i=1;i<n;i++){
            if((position[n-i]-position[n-i-1])<=k) speed[n-i-1]=speed[n-i]+1;
        }
        for(auto &i:speed){
            cout<<i<<" ";
        }
        for(int i=1;i<n;i++){
            if(x>=speed[n-1-i]){
                g++;
                x = speed[n-1-i];
            }
        }
        return g - ns;
    }
};