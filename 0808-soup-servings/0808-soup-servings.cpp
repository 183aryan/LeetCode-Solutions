class Solution {
public:
    double f(int a, int b, vector<vector<double>>& dp){
        if(a <= 0 and b <= 0) return 0.5;
        if(b <= 0) return 0;
        if(a <= 0) return 1;
        
        if(dp[a][b] != -1) return dp[a][b];
        
        double ans = 0;
        ans += f(a-100, b, dp) +
               f(a-75, b-25, dp) +
               f(a-50, b-50, dp) +
               f(a-25, b-75, dp);
        return dp[a][b] = ans*0.25;
    }
    double soupServings(int n) { 
        if(n >= 4800) return 1;
        vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
        return f(n, n, dp);
    }
};