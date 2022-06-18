// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans = -1;
    void f(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, vector<vector<bool>>& visited, int n, int m, int res){
        if(xs < 0 || ys < 0 || xs >= n || ys >= m || visited[xs][ys] == true || matrix[xs][ys] == 0){
            return;
        }
        if(xs == xd && ys == yd){
            ans = max(res, ans);
            return;
        }
        visited[xs][ys] = true;
        f(matrix, xs + 1, ys, xd, yd, visited, n, m, res + 1);
        f(matrix, xs - 1, ys, xd, yd, visited, n, m, res + 1);
        f(matrix, xs, ys + 1, xd, yd, visited, n, m, res + 1);
        f(matrix, xs, ys - 1, xd, yd, visited, n, m, res + 1);
        
        visited[xs][ys] = false;
    }



    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        f(matrix, xs, ys, xd, yd, visited,n, m, 0);
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends