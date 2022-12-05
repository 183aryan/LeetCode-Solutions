//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> maze, int n, int m, int k) {
        int dx[4] = {1, 0, 0, -1};
        int dy[4] = {0, 1, -1, 0};
        
        queue<vector<int>> q;
        q.push({0, 0, k});
        
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool> (k+1, false)));
        visited[0][0][k] = true;
        
        int dist = 0;
        while(q.empty() == false){
            int sz = q.size();
            while(sz--){
                auto x = q.front();
                q.pop();
                if(x[0] == n-1 and x[1] == m-1) return dist;
                
                for(int i=0;i<4;i++){
                    int new_x = x[0] + dx[i];
                    int new_y = x[1] + dy[i];
                    int new_k = x[2];
                    
                    if(new_x >= 0 and new_y >= 0 and new_x < n and new_y < m){
                        if(maze[new_x][new_y] == 0 and visited[new_x][new_y][new_k] == false){
                            q.push({new_x, new_y, new_k});
                            visited[new_x][new_y][new_k] = true;
                        }
                        else if(maze[new_x][new_y] == 1 and new_k > 0 and visited[new_x][new_y][new_k-1] == false){
                            q.push({new_x, new_y, new_k-1});
                            visited[new_x][new_y][new_k-1] = true;
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends