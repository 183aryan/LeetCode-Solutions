class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(grid[i][j] == 0 || visited[i][j] == true) return;
        
        visited[i][j] = true;
        
        dfs(i+1, j, m, n, grid, visited);
        dfs(i-1, j, m, n, grid, visited);
        dfs(i, j+1, m, n, grid, visited);
        dfs(i, j-1, m, n, grid, visited);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            if(grid[i][0] == 1 and visited[i][0] == false){
                dfs(i, 0, m, n, grid, visited);
            }
            
            if(grid[i][n-1] == 1 and visited[i][n-1] == false){
                dfs(i, n-1, m, n, grid, visited);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1 and visited[0][i] == false){
                dfs(0, i, m, n, grid, visited);
            }
            
            if(grid[m-1][i] == 1 and visited[m-1][i] == false){
                dfs(m-1, i, m, n, grid, visited);
            }
        }
        
        int cnt=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 and visited[i][j] == false) cnt++;
            }
        }
        return cnt;
    }
};