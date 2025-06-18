class Solution {
public:
    vector<int> twoSum(vector<int>& nb, int t) {
        int i = 0, j = nb.size()-1;
        while(i<j){
            if((nb[i]+nb[j])==t){
                return {i+1,j+1};
            }
            else if((nb[i]+nb[j])>t)
                j--;
            else i++;
        }
        return {-1};
    }
};