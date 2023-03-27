class Solution
{
    public:
    int f(int i, int j, vector<vector < int>> &grid, vector<vector < int>> &dp){
        if(i == 0 and j == 0) return grid[i][j];
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = INT_MAX, left = INT_MAX;
        if(i >= 1) up = grid[i][j] + f(i-1, j, grid, dp);
        if(j >= 1) left = grid[i][j] + f(i, j-1, grid, dp);
        
        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector < int>> &grid){
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        return f(grid.size()-1, grid[0].size()-1, grid, dp);
    }
};