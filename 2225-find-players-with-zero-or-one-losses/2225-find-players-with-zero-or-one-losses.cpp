class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> um;
        set<int> win, loss;
        vector<vector<int>> v;
        vector<int> onlyWin, onlyOneLoss;
        
        for(auto it:matches){
            win.insert(it[0]);
        }
        for(auto it:matches){
            loss.insert(it[1]);
            um[it[1]]++;
        }
        
        for(auto it:win){
            if(um[it] == 0) onlyWin.push_back(it);
        }
        
        for(auto it:loss){
            if(um[it] == 1) onlyOneLoss.push_back(it);
        }
        
        v.push_back(onlyWin);
        v.push_back(onlyOneLoss);
        
        return v;
    }
};