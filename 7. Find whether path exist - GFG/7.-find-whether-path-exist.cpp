// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool DFS(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return false;
        if(grid[i][j] == 2) return true;
        
        
        grid[i][j] = 0;
        bool res = DFS(grid,i - 1,j) || DFS(grid,i,j + 1) || DFS(grid,i + 1,j) || DFS(grid,i,j - 1);
        grid[i][j] = 3;
        
        return res;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return DFS(grid,i,j);
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends