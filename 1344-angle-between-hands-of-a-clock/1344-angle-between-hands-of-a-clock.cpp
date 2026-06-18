class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour*30 + (minutes*1.0)/2.0;
        double mr = minutes*6.0;
        double solr = abs(hr-mr);
        return solr>180?360-solr:solr;
    }
};