class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int cap){
            if(ind == prices.size()) return 0;
            if(cap >= 2) return 0; 
            int profit = 0;
            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
            if(buy){
                profit = max(-prices[ind]+f(ind+1,0,prices,dp,cap), 0+f(ind+1,1,prices,dp,cap));
            }
            else{
                profit = max(prices[ind]+f(ind+1,1,prices,dp,cap+1),0+f(ind+1,0,prices,dp,cap));
            }
            return dp[ind][buy][cap] = profit;
        }
    int maxProfit(vector<int>& prices) {
           vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
           return f(0,1,prices,dp,0);
    }
};