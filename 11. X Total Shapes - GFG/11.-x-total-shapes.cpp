// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void DFS(vector<vector<char>>& grid,int i,int j,vector<vector<bool>> &visited){
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == 'O' || visited[i][j] == true) return;
        
        visited[i][j] = true;
        
        DFS(grid,i+1,j,visited);
        DFS(grid,i-1,j,visited);
        DFS(grid,i,j+1,visited);
        DFS(grid,i,j-1,visited);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int cnt = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 'X' and visited[i][j] == false){
                    DFS(grid,i,j,visited);
                    cnt++;
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends