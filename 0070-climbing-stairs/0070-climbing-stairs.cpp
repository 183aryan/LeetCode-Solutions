class Solution {
public:
//     int f(int ind, vector<int>& dp){
//         if(ind < 0) return 0;
//         if(ind == 0) return 1;
//         if(dp[ind] != -1) return dp[ind];
//         int one = 0, two = 0;
//         if(ind >= 1) one = f(ind-1, dp);
//         if(ind >= 2) two = f(ind-2, dp);
        
//         return dp[ind] = one+two;
//     }
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        // return f(n, dp);
        
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};