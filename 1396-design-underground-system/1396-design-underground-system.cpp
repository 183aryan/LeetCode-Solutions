class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<int, int>> route;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startEnd = checkIns[id].first + '-' + stationName;
        route[startEnd] = {route[startEnd].first + (t - checkIns[id].second), route[startEnd].second + 1};
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = route[startStation + '-' + endStation];
        return (double)p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */