class Solution {
public:
    string tobinary(int &num){
        string s;
        while(num){
            s.push_back((char)((num&1)+48));
            // num/=2;
            num>>=1;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0,4)),month = stoi(date.substr(5,2)),day = stoi(date.substr(8,2));
        return tobinary(year)+"-"+tobinary(month)+"-"+tobinary(day);
    }
};