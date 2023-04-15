class Solution {
public:
    int f(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        if (dp[i][k] != -1) return dp[i][k];
        if (i == piles.size() || k == 0) return 0;
        int res = f(i + 1, k, piles, dp), cur = 0;
        for (int j = 0; j < piles[i].size() && j < k; j++) {
            cur += piles[i][j];
            res = max(res, f(i + 1, k - j - 1, piles, dp) + cur);
        }
        dp[i][k] = res;
        return res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return f(0, k, piles, dp);
    }
};