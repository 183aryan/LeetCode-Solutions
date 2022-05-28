// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  void DFS(int src,int parent,vector<int>& visited,vector<int>& tin,vector<int>& low,int timer,
  vector<int> adj[],vector<int>& isArt){
      
      visited[src] = 1;
      tin[src] = low[src] = timer++;
      int child = 0;
      for(auto it:adj[src]){
          
          if(!visited[it]){
              DFS(it,src,visited,tin,low,timer,adj,isArt);
              low[src] = min(low[src],low[it]);
              if(low[it] >= tin[src] and parent != -1) isArt[src] = 1;
              child++;
          }
          else{
              low[src] = min(low[src],tin[it]);
          }
      }
      if(parent == -1 and child > 1) isArt[src] = 1;
    
    }   
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> tin(V,-1),low(V,-1),isArt(V,0);
        int timer = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]) DFS(i,-1,visited,tin,low,timer,adj,isArt);
        }
        
        vector<int> v;
        for(int i=0;i<V;i++){
            if(isArt[i] == 1) v.push_back(i);
        }
        if(v.size() == 0) v.push_back(-1);
        return v;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends