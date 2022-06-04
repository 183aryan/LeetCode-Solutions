class Solution {
public:
    bool dfs(int src,vector<int> adj[],vector<int>& visited,vector<int>& recSt){
        visited[src] = 1;
        recSt[src] = 1;
        for(auto x:adj[src]){
            if(visited[x] == 0 and dfs(x,adj,visited,recSt)) return true;
            else if(visited[x] == 1 and recSt[x] == 1) return true;
        }
        recSt[src] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> recSt(numCourses,0);
        
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,recSt)) return false;
            }
        }
        return true;
    }
};