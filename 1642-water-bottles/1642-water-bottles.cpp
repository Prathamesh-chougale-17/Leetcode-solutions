class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int sumi = nb,rm = 0;
        while(nb>=ne){
            sumi += nb/ne;
            nb = nb/ne + nb%ne;
            cout<<nb<<endl;
        }
        return sumi;
    }
};