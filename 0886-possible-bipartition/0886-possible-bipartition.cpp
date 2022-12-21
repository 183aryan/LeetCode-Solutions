class Solution {
public:
    bool bipartite(int src, vector<vector<int>>& adj, vector<int>& color){
        if(color[src] == -1) color[src] = 0;
        
        for(auto it:adj[src]){
            if(color[it] == -1){
                color[it] = 1 - color[src];
                if(not bipartite(it, adj, color)) return false;
            }
            else if(color[it] == color[src]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(not bipartite(i, adj, color)) return false;
            }
        }
        return true;
    }
};