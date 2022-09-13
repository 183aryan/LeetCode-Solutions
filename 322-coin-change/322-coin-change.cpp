class Solution {
public:
    int f(int ind, vector<int>& coins, int T, vector<vector<int>>& dp){
        if(ind == 0){
            if(T%coins[ind] == 0) return T/coins[ind];
            else return 1e9;
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        int notTake = 0 + f(ind-1,coins,T,dp);
        int take = INT_MAX;
        if(coins[ind] <= T) take = 1 + f(ind, coins, T-coins[ind], dp);
        
        return dp[ind][T] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1,-1));
        int res = f(coins.size()-1, coins, amount, dp);
        return (res >= 1e9) ? -1:res;
    }
};