class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int x = -1;
        vector<int> noeq;
        for(int &i:nums){
            if(x!=i){
                noeq.push_back(i);
                x = i;
            }
        }
        int  n = noeq.size();
        if(n<3)return 0;
        for(int i=1;i<n-1;i++){
            if(((noeq[i]>noeq[i-1]) && (noeq[i]>noeq[i+1])) || ((noeq[i]<noeq[i-1])&& (noeq[i]<noeq[i+1]))) count++;
        }
        return count;
    }
};