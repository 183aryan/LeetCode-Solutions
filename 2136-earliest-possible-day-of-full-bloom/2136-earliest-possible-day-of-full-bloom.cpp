class Solution {
public:
    static bool cmp(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> vp;
        for(int i=0;i<plantTime.size();i++) vp.push_back({plantTime[i], growTime[i]});
        
        sort(vp.begin(), vp.end(), cmp);
        
        int time = 0;
        int total = 0;
        
        for(int i=0;i<growTime.size();i++){
            time += vp[i].first;
            total = max(total, time + vp[i].second);
        }
        
        return total;
    }
};