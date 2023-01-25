class Solution {
public:
    void dfs(int node, vector<int>& edges,vector<int>& v,int dist){
        if(node != -1 and v[node] == -1){
            v[node] = dist;
            dfs(edges[node],edges,v,dist+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans = -1;
        int minDis = INT_MAX;
    
        int n = edges.size();
        vector<int> v1(n,-1), v2(n,-1);
        
        dfs(node1,edges,v1,0);
        dfs(node2,edges,v2,0);
        
        for(int i=0;i<n;i++){
            if(min(v1[i],v2[i]) >= 0 and max(v1[i],v2[i]) < minDis){
                minDis = max(v1[i],v2[i]);
                ans = i;
            }
        }
        return ans;
    }
};