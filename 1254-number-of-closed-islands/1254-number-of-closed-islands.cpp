class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;
        if(grid[i][j] == 1) return true;
        
        grid[i][j] = 1;
        
        bool d1 = dfs(i+1, j, grid);
        bool d2 = dfs(i, j+1, grid);
        bool d3 = dfs(i-1, j, grid);
        bool d4 = dfs(i, j-1, grid);
        return d1 && d2 && d3 && d4;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    if(dfs(i, j, grid)) cnt++;
                }
            }
        }
        
        return cnt;
    }
};