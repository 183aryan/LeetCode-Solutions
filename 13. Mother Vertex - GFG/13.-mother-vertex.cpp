// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void DFS(int i,vector<int> adj[],vector<bool>& visited,int &cnt){
        visited[i] = true;
        cnt++;
        for(auto x:adj[i]){
            if(!visited[x]) DFS(x,adj,visited,cnt);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    for(int i=0;i<V;i++){
	        vector<bool> visited(V,false);
	        int cnt = 0;
            DFS(i,adj,visited,cnt);
	        if(cnt == V) return i;
	    }
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends