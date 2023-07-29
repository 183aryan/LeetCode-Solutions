class Solution {
public:
    long long f(int idx, int n, string& s, char prev, vector<vector<long long>>& dp){
        if(idx == n) return 0;
        if(dp[idx][prev-'0'] != -1) return dp[idx][prev-'0'];
        
        if(s[idx] == prev) return dp[idx][prev-'0'] = f(idx+1, n, s, s[idx], dp);
        return dp[idx][prev-'0'] = min(idx+f(idx+1, n, s, s[idx], dp), n-idx+f(idx+1, n, s, s[idx], dp));
    }
    long long minimumCost(string s) {
        vector<vector<long long>> dp(s.size(), vector<long long> (2, -1));
        return f(1, s.size(), s, s[0], dp);
    }
};