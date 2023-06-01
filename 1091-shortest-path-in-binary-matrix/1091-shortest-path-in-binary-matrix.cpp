class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0) return -1;
        if(grid[n-1][m-1] != 0) return -1;
        
        queue<pair<int, int>> q;
        
        vector<int>dx = {-1,-1,-1,0,0,1,1,1};
        vector<int>dy = {-1,0,1,-1,1,0,-1,1};
        
        grid[0][0] = 1;
        q.push({0, 0});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == n-1 and y == m-1) return grid[x][y];
            
            for(int i=0;i<8;i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if(new_x >= 0 and new_y >= 0 and new_x < n and new_y < m and grid[new_x][new_y] == 0){
                    grid[new_x][new_y] = grid[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return -1;
    }
};