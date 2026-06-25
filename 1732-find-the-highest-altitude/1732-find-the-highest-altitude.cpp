class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0,sumi = 0;
        for(auto &i:gain){
            sumi+=i;
            maxi=max(sumi,maxi);
        }
        return maxi;
    }
};