class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& graph,vector<int>& visited,int& res,vector<int>& values,int node,int score,int time,int& maxTime){
        if(time > maxTime) return;
        if(visited[node] == 0) score += values[node];
        
        visited[node]++;
        
        if(node == 0) res = max(res,score);
        
        for(auto it:graph[node]){
            int x = it.first;
            int t = it.second;
            dfs(graph,visited,res,values,x,score,time+t,maxTime);
        }
        visited[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int res = values[0];
        
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> visited(n,0);
        dfs(graph,visited,res,values,0,0,0,maxTime);
        return res;
    }
};