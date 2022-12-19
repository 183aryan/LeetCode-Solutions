class Solution {
public:
    bool f(int src, int dst, vector<vector<int>>& adj, vector<bool>& visited){
        if(src == dst) return true;
        
        if(not visited[src]){
            visited[src] = true;
            for(auto& it:adj[src]){
                if(not visited[it]){
                    if(f(it, dst, adj, visited)) return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n+1, false);
        
        return f(source, destination, adj, visited);
    }
};