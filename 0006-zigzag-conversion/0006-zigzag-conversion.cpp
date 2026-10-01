class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> sl[numRows];
        if(numRows==1)return s;
        int x=-1,pos = 1;
        for(auto &i:s){
            if(pos){
                x++;
                if(x==(numRows)){
                    x-=2;
                    pos = 0;
                    // continue;
                }
                sl[x].push_back(i);
            }else{
                x--;
                if(x==-1){
                    x+=2;
                    pos=1;
                    // continue;
                }
                sl[x].push_back(i);
            }
        }
        string sol;
        for(auto &i:sl){
            for(auto &j:i){
                sol+=j;
                cout<<j<<' ';
            }
            cout<<endl;
        }
        return sol;
    }
};