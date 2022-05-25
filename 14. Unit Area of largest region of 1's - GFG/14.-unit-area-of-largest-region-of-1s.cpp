// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int DFS(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2)
        return 0;
        
        grid[i][j] = 2;
        
        return 1+DFS(grid,i+1,j)+DFS(grid,i-1,j)+DFS(grid,i,j+1)+DFS(grid,i,j-1)+DFS(grid,i+1,j+1)+
        DFS(grid,i-1,j-1)+DFS(grid,i+1,j-1)+DFS(grid,i-1,j+1);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    cnt = max(cnt,DFS(grid,i,j));
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends