class Solution {
public:
    int f(vector<int>& days, vector<int>& costs, vector<int>& dp, int index){
//         if(ind >= days.size()) return 0;
//         if(valid >= days[ind]) return f(days,costs,ind+1,valid,dp);
//         if(dp[ind] != -1) return dp[ind];
//         int mini = INT_MAX;
//         mini = min(mini,costs[0] + f(days,costs,ind+1,days[ind],dp));
//         mini = min(mini,costs[1] + f(days,costs,ind+1,days[ind]+6,dp));
//         mini = min(mini,costs[2] + f(days,costs,ind+1,days[ind]+29,dp));
        
//         return dp[ind] = mini;
        
        if(index >= days.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int opt1 = costs[0] + f(days, costs, dp, index+1);
        
        int i;
        for(i=index;i<days.size() and days[i] < days[index]+7;i++);
        int opt2 = costs[1] + f(days, costs, dp, i);
        
        for(i=index;i<days.size() and days[i] < days[index]+30;i++);
        int opt3 = costs[2] + f(days, costs, dp, i);
        
        return dp[index] = min({opt1, opt2, opt3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return f(days, costs, dp, 0);
    }
};