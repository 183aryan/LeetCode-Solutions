// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &ans,vector<int> &curr){
        if(i >= n || j >= m) return;
        
        if(i == n-1 and j == m-1){
            curr.push_back(grid[i][j]);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(grid[i][j]);
        dfs(i+1,j,n,m,grid,ans,curr);
        dfs(i,j+1,n,m,grid,ans,curr);
        curr.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(0,0,n,m,grid,ans,curr);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends