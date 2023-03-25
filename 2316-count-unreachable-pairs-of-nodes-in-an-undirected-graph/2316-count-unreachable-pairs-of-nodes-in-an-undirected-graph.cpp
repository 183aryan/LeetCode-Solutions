class Solution {
public:
    long long int dfs(int src, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[src]) return 0;
        long long int cnt=1;
        visited[src] = true;
        for(auto x:adj[src]){
            if(visited[x]==false){
                cnt += dfs(x, adj, visited);
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long int total = n;
        long long int ans = 0;
        
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, false);
        
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                long long int curr = dfs(i, adj, visited);
                total = total - curr;
                cout << total << " ";
                ans += curr*total;
            }
        }
        return ans;
    }
};