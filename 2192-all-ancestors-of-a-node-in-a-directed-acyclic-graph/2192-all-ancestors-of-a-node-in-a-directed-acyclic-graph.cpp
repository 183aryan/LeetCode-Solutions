class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> in_degree(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            in_degree[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_degree[i] == 0) q.push(i);
        }
        
        set<int> s[n];              // set of array
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it:adj[curr]){
                s[it].insert(curr);
                
                for(auto it2:s[curr]){
                    s[it].insert(it2);
                }
                if(--in_degree[it] == 0){
                    q.push(it);
                }
            }
        }
        vector<vector<int>> v(n,vector<int>());
        for(int i=0;i<n;i++){
            v[i] = vector<int>(s[i].begin(),s[i].end());
        }
        return v;    
    }
};