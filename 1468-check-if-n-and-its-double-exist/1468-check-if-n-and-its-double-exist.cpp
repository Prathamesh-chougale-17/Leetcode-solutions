class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> um;
        for(auto &i:arr){
            if(um[2*i]==1)return true;
            if(i%2==0 && um[i/2]==1)return true;
            um[i]=1;
        }
        return false;
    }
};