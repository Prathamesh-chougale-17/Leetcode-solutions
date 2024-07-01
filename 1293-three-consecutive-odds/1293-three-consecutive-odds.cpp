class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int co{0};
        for(int i = 0;i<arr.size();i++){
            
            if(arr[i]%2){
                co++;
                if(co==3){
                    return true;
                }
            }
            else{
                co=0;
            }
        }
        return false;
    }
};