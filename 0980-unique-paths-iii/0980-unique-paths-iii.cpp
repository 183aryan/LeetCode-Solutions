class Solution {
public:
    int ans=0,cnt=0;
    
    void dfs(int i, int j, int temp, vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) return;
        
        if(grid[i][j] == 2){
            if(cnt == temp){
                ans++;
            }
            return;
        }
        grid[i][j] = -1;
        
        dfs(i+1, j, temp+1, grid);
        dfs(i-1, j, temp+1, grid);
        dfs(i, j+1, temp+1, grid);
        dfs(i, j-1, temp+1, grid);
        
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x=0, y=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0) cnt++;
                else if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        cnt++;
        dfs(x, y, 0, grid);
        
        return ans;
    }
};