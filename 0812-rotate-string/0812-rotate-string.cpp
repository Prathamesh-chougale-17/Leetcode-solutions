class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        string cont = s+s;
        for(int i=0;i<n;i++){
            if(goal==cont.substr(i,n))return true;
        }
        return false;
    }
};