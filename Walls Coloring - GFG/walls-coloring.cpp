//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int f(int i, int j, vector<vector<int>>& colors, vector<vector<int>>& dp, int n){
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for(int k=0;k<3;k++){
            if(j == k) continue;
            mini = min(mini, colors[i][k] + f(i+1, k, colors, dp, n));
        }
        return dp[i][j] = mini;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        vector<vector<int>> dp(N+1, vector<int> (3, -1));
        int res = INT_MAX;
        for(int j=0;j<3;j++){
            res = min(res, colors[0][j]+f(1, j, colors, dp, N));
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends