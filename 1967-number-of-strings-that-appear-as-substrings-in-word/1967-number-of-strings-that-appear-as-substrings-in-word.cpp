class Solution {
public:
    bool isthere(string &s,string word,int size,int wsize){
        for(int i=0;i<=(wsize-size);i++){
            if(s==word.substr(i,size))return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size(),sol = 0;
        for(auto &i:patterns){
            if(isthere(i,word,i.size(),n)){
                sol++;
            }
        }
        return sol;
    }
};