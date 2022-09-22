class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));
        // return f(0,1,prices,dp);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy){
                    profit = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};