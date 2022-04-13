class Solution
{
    public:
        int getMaximumConsecutive(vector<int> &coins)
        {
            sort(coins.begin(), coins.end());
            int ans = 1;
            for (int i = 0; i < coins.size(); i++)
            {
                if (coins[i] > ans) break;
                else ans += coins[i];
            }
            return ans;
        }
};