class Solution {
public:
    int mini = INT_MAX;
    void dfs(int ind, vector<pair<int, int>> adj[], vector<bool>& visited){
        visited[ind] = true;
        for(auto &it:adj[ind]){
            mini = min(mini, it.second);
            if(!visited[it.first]){
                dfs(it.first, adj, visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n+1];
        
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        vector<bool> visited(n+1, false);
        
        dfs(1, adj, visited);
        return mini;
    }
};