class TimeMap {
public:
    map<string, vector<pair<int, string>>> umv;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umv[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(umv.find(key) == umv.end()) return "";
        if(umv[key][0].first > timestamp) return "";
        
        int lo=0;
        int hi=umv[key].size()-1;
        string res = "";
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            if(umv[key][mid].first == timestamp) return umv[key][mid].second;
            else if(umv[key][mid].first < timestamp){
                res = umv[key][mid].second;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */