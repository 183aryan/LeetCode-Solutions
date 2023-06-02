class Solution {
public:
    void dfs(int& i, int& cnt, vector<bool>& visited, vector<vector<int>>& graph){
        visited[i] = true;
        cnt++;
        
        for(int j=0;j<graph[i].size();j++){
            if(visited[graph[i][j]] == false) dfs(graph[i][j], cnt, visited, graph);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;i++){
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            
            for(int j=0;j<n;j++){
                if(i == j) continue;
                
                long long int x = abs(x1 - bombs[j][0]);
                long long int y = abs(y1 - bombs[j][1]);
                
                if(sqrt(x*x + y*y) <= r1){
                    graph[i].push_back(j);
                }
            }
        }
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            int cnt=0;
            vector<bool> visited(n, false);
            dfs(i, cnt, visited, graph);
            ans = max(ans, cnt);
        }
        return ans;
    }
};