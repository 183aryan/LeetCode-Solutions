// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
     void DFS(vector<vector<char>>& grid,int i,int j){
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == '2' || grid[i][j] == '0') return;
        
        grid[i][j] = '2';
        
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
        DFS(grid,i+1,j+1);
        DFS(grid,i-1,j-1);
        DFS(grid,i+1,j-1);
        DFS(grid,i-1,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    DFS(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends