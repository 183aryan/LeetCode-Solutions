class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int profit = 0;
            int ans = prices[0];
            for (int i = 0; i < prices.size(); i++)
            {
                ans = min(ans, prices[i]);
                profit = max(profit, prices[i] - ans);
            }
            return profit;
        }
};