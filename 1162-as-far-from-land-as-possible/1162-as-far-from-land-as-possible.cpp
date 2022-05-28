class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        if(q.size() == grid.size()*grid[0].size()) return -1;
        int cnt = 0;
        
        while(!q.empty()){
            int sz = q.size();
            cnt++;
            for(int i=0;i<sz;i++){
                int currx = q.front().first;
                int curry = q.front().second;
                q.pop();
            
                for(int i=0;i<4;i++){
                   int nx = currx + dx[i];
                   int ny = curry + dy[i];
                
                   if(nx >= 0 and ny >= 0 and nx < grid.size() and ny < grid[0].size() and grid[nx][ny] == 0){
                       q.push({nx,ny});
                       grid[nx][ny] = 1;
                   }
                }
             }
         }
        return cnt-1;
    }
};