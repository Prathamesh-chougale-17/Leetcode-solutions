class Solution {
public:
    string tobinary(int num){
        string s;
        while(num){
            s = to_string(num%2)+s;
            num/=2;
        }
        return s;
    }
    string convertDateToBinary(string date) {
        return tobinary(stoi(date.substr(0,4)))+"-"+tobinary(stoi(date.substr(5,2)))+"-"+tobinary(stoi(date.substr(8,2)));
    }
};