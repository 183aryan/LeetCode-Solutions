class Solution {
public:
    bool bipartiteDFS(int src,vector<vector<int>>& graph,vector<int>& color){
        if(color[src] == -1) color[src] = 1;
        for(auto it:graph[src]){
            if(color[it] == -1){
                color[it] = 1 - color[src];
                if(bipartiteDFS(it,graph,color) == false) return false;
            }
            else if(color[it] == color[src]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(bipartiteDFS(i,graph,color) == false) return false;
            }
        }
        return true;
    }
};