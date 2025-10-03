class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int sumi=nb;
        while(nb>=ne){
            sumi++;
            nb-=ne;
            nb++;
            ne++;
            cout<<nb<<" "<<ne<<endl;
        }
        return sumi;
    }
};