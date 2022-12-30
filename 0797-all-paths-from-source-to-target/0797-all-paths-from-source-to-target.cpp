class Solution {
public:
    vector<vector<int>> v;
    vector<int> res;
    
    void dfs(int src, int dest, vector<vector<int>>& graph){
        res.push_back(src);
        if(src == dest) v.push_back(res);
        for(auto it:graph[src]){
            dfs(it, dest, graph);
        }
        res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph.size()-1, graph);
        
        return v;
    }
};