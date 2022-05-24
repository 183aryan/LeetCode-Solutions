// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    int level = 0;
	    visited[0] = true;
	    queue<int> q;
	    q.push(0);
	    
	    while(!q.empty()){
	        int cnt = q.size();
	        for(int i=0;i<cnt;i++){
	            auto x=q.front();
	            q.pop();
	            if(x == X) return level;
	            
	            for(auto i:adj[x]){
	                if(!visited[i]){
	                    visited[i] = true;
	                    q.push(i);
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends