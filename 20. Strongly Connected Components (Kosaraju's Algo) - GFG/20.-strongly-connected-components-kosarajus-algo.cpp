// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> st;
	void DFS(int src,vector<int> adj[],vector<bool>& visited){
	    visited[src] = true;
	    for(auto it:adj[src]){
	        if(!visited[it]) DFS(it,adj,visited);
	    }
	    st.push(src);
	}
	void rDFS(int s,vector<int> transpose[],vector<bool>& visited){
	    visited[s] = true;
	    for(auto it:transpose[s]){
	        if(!visited[it]) rDFS(it,transpose,visited);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(i,adj,visited);
            }
        }
        
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
            for(auto it:adj[i]) transpose[it].push_back(i);
        }
        int cnt = 0;
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            if(!visited[x]){
                cnt++;
                rDFS(x,transpose,visited);
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends