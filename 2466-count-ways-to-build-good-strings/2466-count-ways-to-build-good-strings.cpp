class Solution {
public:
    int ans=0;
    int mod = 1e9+7;
    int f(int len, int zero, int one, vector<int>& dp){
        if(len == 0) return 1;
        if(len < 0) return 0;
        
        if(dp[len] != -1) return dp[len];
        return dp[len] = (f(len-zero, zero, one, dp) + f(len-one, zero, one, dp))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        
        for(int i=low;i<=high;i++){
            ans = (ans + f(i, zero, one, dp))%mod;
        }
        return ans;
    }
};