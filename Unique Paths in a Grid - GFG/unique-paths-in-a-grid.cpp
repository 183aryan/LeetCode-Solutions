//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
const int mod=1e9+7;
class Solution {
  public:
    // int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i < 0 || j < 0 || grid[i][j] == 0) return 0;
    //     if(i == 0 and j == 0) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int up = (f(i-1, j, grid, dp))%mod;
    //     int left = (f(i, j-1, grid, dp))%mod;
        
    //     return dp[i][j] = (up + left)%mod;
    // }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n, vector<int> (m, 0));
        // return f(n-1, m-1, grid, dp);
        
        for(int i=0;i<n;i++) dp[i][0] = 0;
        for(int j=0;j<m;j++) dp[0][j] = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) dp[i][j] = 0;
                else if(i == 0 and j == 0) dp[i][j] = 1;
                else{
                    int up=0, left=0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    
                    dp[i][j] = (up + left)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends