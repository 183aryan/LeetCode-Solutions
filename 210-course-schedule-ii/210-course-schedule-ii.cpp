class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses,0);
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            in_degree[x[0]]++;
        }
        queue<int> q;
        vector<int> v;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i] == 0) q.push(i);
        }
        while(q.empty() == false){
            auto x = q.front();
            q.pop();
            v.push_back(x);
            for(auto it:adj[x]){
                if(--in_degree[it] == 0) q.push(it);
            }
        }
        if(v.size() == numCourses) return v;
        return {};
    }
};