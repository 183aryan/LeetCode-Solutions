class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];
        int ans = n;
        for(int i=1;i*i<=n;i++){
            ans = min(ans, 1+f(n-i*i, dp));
        }
        dp[n] = ans;
        return ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};