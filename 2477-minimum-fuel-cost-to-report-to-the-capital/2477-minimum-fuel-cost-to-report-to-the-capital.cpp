class Solution {
public:
    long long res=0;
    long long f(int src, vector<vector<int>>& adj, int seats, vector<int>& visited){
        visited[src] = 1;
        int cnt=1;
        for(auto it:adj[src]){
            if(visited[it] == -1) cnt += f(it, adj, seats, visited);
        }
        if(cnt <= seats) res += 1;
        else{
            res += ceil(cnt/(seats*1.0));
        }
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adj(n+1);
        
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n+1, -1);
        
        visited[0] = 1;
        
        for(auto it:adj[0]){
            f(it, adj, seats, visited);
        }
        
        return res;
    }
};