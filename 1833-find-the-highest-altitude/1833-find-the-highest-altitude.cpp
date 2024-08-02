class Solution {
public:
    vector<int> prefixsum(vector<int>& gain){
        vector<int> prefix(gain.size()+1);
        for(int i=1;i<=gain.size();i++){
            prefix[i] = prefix[i-1]+gain[i-1];
        }
        return prefix;
    }
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        vector<int> altitude = prefixsum(gain);
        for(auto &i:altitude) maxi = max(maxi,i);
        return maxi;
    }
};