class Solution {
public:
    void DFS(int i,vector<vector<int>>& adj,vector<bool>& visited){
        visited[i] = true;
        for(auto x:adj[i]){
            if(!visited[x]) DFS(x,adj,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        vector<vector<int>> adj(n);
        for(auto v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){ 
                DFS(i,adj,visited);
                cnt++;
            }   
        }
        return cnt-1;
    }
};