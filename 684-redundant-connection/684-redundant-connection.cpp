class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool>& visited,int src,int parent){
        visited[src] = true; 
        
        for(auto x:graph[src]){
            if(visited[x] == false){
                if(dfs(graph,visited,x,src)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> visited(n+1,false);
        vector<vector<int>> graph(n+1);
        for(auto e:edges){
            fill(visited.begin(),visited.end(),false);
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            if(dfs(graph,visited,e[0],-1)) return e;
        }
        return {};
    }
};