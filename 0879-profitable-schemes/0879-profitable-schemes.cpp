class Solution {
public:
    int mod = 1e9+7;
    int f(int index, int n, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(n < 0) return 0;
        if(index == group.size()){
            if(minProfit > 0) return 0;
            return 1;
        }
        
        if(minProfit < 0) minProfit = 0;
        if(dp[minProfit][n][index] != -1) return dp[minProfit][n][index];
        
        int pick = f(index+1, n - group[index], minProfit - profit[index], group, profit, dp);
        int notPick = f(index+1, n, minProfit, group, profit, dp);
        
        return dp[minProfit][n][index] = (pick + notPick)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(minProfit+1, vector<vector<int>> (n+1, vector<int> (group.size()+1, -1)));
        return f(0, n, minProfit, group, profit, dp);
    }
};