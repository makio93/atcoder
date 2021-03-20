#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    map<int, pair<string, int>> checkinlst;
    map<pair<string, string>, pair<long long, int>> timelst;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) { checkinlst[id] = { stationName, t }; }
    
    void checkOut(int id, string stationName, int t) {
        timelst[{checkinlst[id].first,stationName}].first += t - checkinlst[id].second;
        timelst[{checkinlst[id].first,stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) { return (double)timelst[{startStation,endStation}].first / timelst[{startStation,endStation}].second; }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(){
    return 0;
}
