// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void DFS(int V,vector<int> adj[],int source,int destination,int &cnt){
        if(source == destination){
            cnt++;
            return;
        }
        for(auto x:adj[source]) DFS(V,adj,x,destination,cnt);
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool> visited(V,false);
        int cnt = 0;
        DFS(V,adj,source,destination,cnt);
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends