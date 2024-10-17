class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int pos=0;
        for(int i=0;i<s.size()-1;i++){
            char maxi = s[i];
            for(int j=1+i;j<s.size();j++){
                if(maxi<=s[j]){
                    maxi = s[j];
                    pos = j;
                }
            }
            if(maxi > s[i]){
                swap(s[i],s[pos]);
                break;
            }
        }
        return stoi(s);
    }
};