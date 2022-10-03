class Solution {
public:
    int f(int ind, string& colors, vector<int>& neededTime, vector<int>& dp, char prev, int prevCost){
        if(ind >= colors.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        if(colors[ind] != prev) return dp[ind] = f(ind+1, colors, neededTime, dp, colors[ind], neededTime[ind]);
        
        return dp[ind] = min(prevCost, neededTime[ind]) + f(ind+1,colors,neededTime, dp, colors[ind], max(prevCost, neededTime[ind]));
    }
    int minCost(string colors, vector<int>& neededTime) {
        set<char> s;
        for(int i=0;i<colors.size();i++){
            s.insert(colors[i]);
        }
        if(s.size() == colors.size()) return 0;
        vector<int> dp(colors.size(), -1);
        return f(0, colors, neededTime, dp, ' ', neededTime[0]);
    }
};