class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it:redEdges) adj[it[0]].push_back({it[1], 0});
        for(auto it:blueEdges) adj[it[0]].push_back({it[1], 1});
        
        vector<int> v(n, -1);
        
        queue<vector<int>> q;
        q.push({0, 0, -1});
        
        while(q.empty() == false){
            auto x = q.front();
            q.pop();
            if(v[x[0]] == -1){
                v[x[0]] = x[1];
            }
            
            for(auto &it:adj[x[0]]){
                if(x[2] != it.second and it.first != -1){
                    q.push({it.first, x[1]+1, it.second});
                    it.first = -1;
                }
            }
        }
        return v;
    }
};