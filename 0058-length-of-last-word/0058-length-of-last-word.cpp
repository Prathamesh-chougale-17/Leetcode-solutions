class Solution {
public:
    int lengthOfLastWord(string s) {
        int x = 0,maxi = 0;
        for(auto &i:s){
            if(i==' '){
                x = 0;
            }else{
                x++;
                maxi = x;
            }
        }
        return maxi;
    }
};