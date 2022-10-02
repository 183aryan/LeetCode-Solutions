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
        long long int cnt=0;
        for(int i=1;i<=k;i++){
            cnt += (f(n-1,k,target-i,dp)%mod);
        }
        return dp[n][target] = cnt%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return f(n, k, target, dp);
    }
};