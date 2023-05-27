class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffixSum(n+1, 0);
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
        for (int i = n-1; i >= 0; i--) {
            dp[i] = stoneValue[i] + suffixSum[i+1] - dp[i+1];
            for (int k = i+1; k < i+3 && k < n; k++) {
                dp[i] = max(dp[i],  suffixSum[i]-dp[k+1]);
            }
        }
        if (dp[0]*2 == suffixSum[0])
            return "Tie";
        else if (dp[0]*2 > suffixSum[0])
            return "Alice";
        else
            return "Bob";
    }
};