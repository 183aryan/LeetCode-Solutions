class Solution {
public:
    int mod = 1e9+7;
    int f(int n, vector<int>& dp){
        if(n <= 0) return 1;
        if(dp[n] != -1) return dp[n];
        int cnt = 0;
        cnt = (cnt + (f(n-1, dp)+f(n-2, dp)))%mod;
        return dp[n] = cnt%mod;
    }
    int countHousePlacements(int n) {
        vector<int> dp(n+1, -1);
        long long int x = f(n, dp)%mod;
        return (x*x)%mod;
    }
};