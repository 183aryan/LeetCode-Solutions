class Solution {
public:
    int mod = 1e9+7;
    int f(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || prev>= grid[i][j]) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long cnt = 1;

        cnt += f(i+1, j, grid[i][j], grid, dp)% mod;
        cnt += f(i-1, j, grid[i][j], grid, dp) % mod;
        cnt += f(i, j+1, grid[i][j], grid, dp) % mod;
        cnt += f(i, j-1,  grid[i][j], grid, dp) % mod;

        return dp[i][j] = cnt;
    }
    int countPaths(vector<vector<int>>& grid) {
        long long cnt = 0, n= grid.size(), m= grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1)); 

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                cnt += f(i, j, -1, grid, dp);
            }
        }

        return cnt%mod;
    }
};