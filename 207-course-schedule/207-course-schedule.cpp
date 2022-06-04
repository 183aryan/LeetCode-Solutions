class Solution {
public:
    bool dfs(int src,vector<int> adj[],vector<bool>& visited,vector<bool>& recSt){
        visited[src] = true;
        recSt[src] = true;
        for(auto x:adj[src]){
            if(visited[x] == false and dfs(x,adj,visited,recSt)) return true;
            else if(visited[x] == true and recSt[x] == true) return true;
        }
        recSt[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,0);
        vector<bool> recSt(numCourses,0);
        
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