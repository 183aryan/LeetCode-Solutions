class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
       int m = grid.size(), n = grid[0].size();
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        bool v[m][n][k+1];
    
        memset(v, false, sizeof(v));
    
        queue<vector<int>> q;
        int cnt = 0;
        q.push({0, 0, k});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<int>cur = q.front();
                q.pop();
                if(cur[0] == m-1 and cur[1] == n-1) return cnt;
                 
                for(auto d: dir){
                    int i = cur[0] + d[0]; 
                    int j = cur[1] + d[1];  
                    int obs = cur[2];       
                    
                    if(i>=0 and i<m and j>=0 and j<n){
                        if(grid[i][j] == 0 and !v[i][j][obs]){ 
                            q.push({i, j, obs});
                           
                            v[i][j][obs] = true;
                        }  
                        else if(grid[i][j] == 1 and obs > 0 and !v[i][j][obs-1]){
                            q.push({i, j, obs-1});
                            v[i][j][obs-1] = true;
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};