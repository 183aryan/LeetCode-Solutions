class Solution {
public:
    int mod = 1e9+7;
    int f(int n, int k, int target, vector<vector<int>>& dp){
        if(n < 1){
            if(target==0) return 1;
            return 0;
        }
        if(n >= 1 and target <= 0) return 0;
        
        if(dp[n][target] != -1) return dp[n][target];
        long long int take=0;
        for(int i=1;i<=k;i++){
            take += (f(n-1,k,target-i,dp)%mod);
        }
        return dp[n][target] = take%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+2, vector<int> (target+2, 0));
        // return f(n, k, target, dp);
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                long long take=0;
                for(int ind=1;ind<=k;ind++){
                    if(ind <= j) take += (dp[i-1][j-ind])%mod;
                }
                dp[i][j] = take%mod;
            }
        }
        return dp[n][target];
    }
};