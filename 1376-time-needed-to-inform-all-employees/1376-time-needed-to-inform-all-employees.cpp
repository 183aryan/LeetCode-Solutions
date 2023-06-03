class Solution {
public:
    int maxi = INT_MIN;
    
    void dfs(int headID, int time, vector<int>& informTime, vector<vector<int>>& graph){
        maxi = max(time, maxi);
        for(auto x:graph[headID]){
            // ans += informTime[headID];
            dfs(x, time + informTime[headID], informTime, graph);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            int val = manager[i];
            if(val != -1)
            graph[val].push_back(i);
        }
        dfs(headID, 0, informTime, graph);
        return maxi;
    }
};