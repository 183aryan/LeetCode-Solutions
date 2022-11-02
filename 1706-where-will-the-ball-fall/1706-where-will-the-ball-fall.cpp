class Solution {
public: 
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i >= grid.size()) return j;
        
        if(grid[i][j] == 1 and j+1<grid[0].size() and grid[i][j+1] == 1)
            return dfs(i+1, j+1, grid);
        else if(grid[i][j] == -1 and j-1 >= 0 and grid[i][j-1] == -1)
            return dfs(i+1, j-1, grid);
        else if(grid[i][j] == 1 and j+1 >= grid[0].size()) return -1;
        else return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m);
        
        for(int j=0;j<m;j++){
            ans[j] = dfs(0, j, grid);
        }
        return ans;
    }
};