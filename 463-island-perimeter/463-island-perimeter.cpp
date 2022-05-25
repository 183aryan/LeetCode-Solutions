class Solution {
public:
    int c=0;
    int DFS(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j]==0 ) return 1;
        
        if(visited[i][j]) return 0;
        
        visited[i][j] = true;
        return DFS(grid,i+1,j,visited) + DFS(grid,i-1,j,visited) + DFS(grid,i,j+1,visited)                    +DFS(grid,i,j-1,visited);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return DFS(grid,i,j,visited);
                }
            }
        }
        return 0;
    }
};