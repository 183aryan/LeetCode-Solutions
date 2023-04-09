class Solution {
public:
    bool isCyclic(vector<vector<int>>& adj, vector<int>&visited, int curr){
        if(visited[curr]==2) return true;
        visited[curr]=2;
        for(int i=0;i<adj[curr].size();i++)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        visited[curr]=1;
        return false;
    }

    bool containsCycle(vector<vector<int>>& adj, int n){
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(isCyclic(adj, visited, i))
                    return true;
            }
        }
        return false;
    }
    int largestPathValue(string s, vector<vector<int>>& edges) {
        int n=s.size();
        vector<vector<int>> adj(n, vector<int>());
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        if(containsCycle(adj, n)) return -1;
        
        vector<int> indegree(n, 0);
        
        for(auto it:edges) indegree[it[1]]++;
        
        vector<vector<int>> colorcnt(n, vector<int> (26, 0));
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                colorcnt[i][s[i]-'a']++;
            }
        }
        
        int ans=0;
        while(q.empty() == false){
            auto x = q.front();
            q.pop();
            
            int curr = *max_element(colorcnt[x].begin(), colorcnt[x].end());
            ans = max(ans, curr);
            
            for(auto it:adj[x]){
                for(int i=0;i<26;i++){
                    colorcnt[it][i] = max(colorcnt[it][i], colorcnt[x][i] +(s[it] - 'a' == i ? 1 : 0));
                
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
                
            }
        }
        
        return ans;
    }
};