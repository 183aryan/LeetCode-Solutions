// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int x,vector<int> adj[],vector<bool>& visited,vector<bool>& recSt){
        visited[x] = true;
        recSt[x] = true;
        for(auto i:adj[x]){
            if(visited[i] == false){
                if(DFS(i,adj,visited,recSt) == true) return true;
            }
            else if(recSt[i] == true) return true;
        }
        recSt[x] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> recSt(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                if(DFS(i,adj,visited,recSt) == true) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends