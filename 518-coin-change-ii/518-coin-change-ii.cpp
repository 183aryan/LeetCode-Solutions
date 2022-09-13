class Solution {
public:
    int f(int ind, vector<int>& coins, int T, vector<vector<int>>& dp){
        if(ind == 0){
            return (T%coins[ind] == 0);
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int notTake = f(ind-1,coins,T,dp);
        int take = 0;
        if(coins[ind] <= T) take = f(ind, coins, T-coins[ind], dp);
        
        return dp[ind][T] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1,-1));
        return f(coins.size()-1, coins, amount, dp);
    }
};