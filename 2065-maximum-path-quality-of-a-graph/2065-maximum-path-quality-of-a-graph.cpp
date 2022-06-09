class Solution {
public:
    void dfs(vector<pair<int,int>> adj[],vector<int>& visited,int& res,vector<int>& values,int node,int score,int time,int& maxTime){
        if(time > maxTime) return;
        if(visited[node] == 0) score += values[node];
        
        visited[node]++;
        
        if(node == 0) res = max(res,score);
        
        for(auto it:adj[node]){
            int x = it.first;
            int t = it.second;
            dfs(adj,visited,res,values,x,score,time+t,maxTime);
        }
        visited[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int res = values[0];
        
        vector<pair<int,int>> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int> visited(n,0);
        dfs(adj,visited,res,values,0,0,0,maxTime);
        return res;
    }
};