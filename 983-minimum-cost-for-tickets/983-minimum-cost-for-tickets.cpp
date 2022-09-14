class Solution {
public:
    int f(vector<int>& days, vector<int>& costs, int ind,int valid ,vector<int>& dp){
        if(ind >= days.size()) return 0;
        if(valid >= days[ind]) return f(days,costs,ind+1,valid,dp);
        if(dp[ind] != -1) return dp[ind];
        int mini = INT_MAX;
        mini = min(mini,costs[0] + f(days,costs,ind+1,days[ind],dp));
        mini = min(mini,costs[1] + f(days,costs,ind+1,days[ind]+6,dp));
        mini = min(mini,costs[2] + f(days,costs,ind+1,days[ind]+29,dp));
        
        return dp[ind] = mini;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return f(days, costs, 0, 0,dp);
    }
};