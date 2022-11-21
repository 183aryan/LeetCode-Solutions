class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int lvl = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while(q.empty() == false){
            int sz = q.size();
            lvl++;
            for(int i=0;i<sz;i++){
                auto x = q.front();
                q.pop();
                int row = x.first;
                int col = x.second;
                for(int j=0;j<4;j++){
                    int new_row = row + dx[j];
                    int new_col = col + dy[j];
                
                if(new_row >= 0 and new_col >= 0 and new_row < n and new_col < m){
                    if(maze[new_row][new_col] == '+') continue;
                    if(new_row == 0 || new_col == 0 || new_row == n-1 || new_col == m-1) return lvl;
                
                q.push({new_row, new_col});
                maze[new_row][new_col] = '+';}
            }
            }
        }
        return -1;
    }
};