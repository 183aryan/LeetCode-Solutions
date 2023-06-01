class Solution {
public:
    int mod = 1e9+7;
    int f(int i, int j, int sum, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 and j == 0) return (sum + grid[i][j])%k == 0;
        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        return dp[i][j][sum] = (f(i-1, j, (sum+grid[i][j])%k, k, grid, dp) + f(i, j-1, (sum+grid[i][j])%k, k, grid, dp))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, -1)));
        return f(n-1, m-1, 0, k, grid, dp);
    }
};