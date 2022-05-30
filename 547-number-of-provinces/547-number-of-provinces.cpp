class Solution {
public:
    void DFS(int src,vector<vector<int>>&isConnected,vector<bool>&visited)
    {
        visited[src]=true;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i]){
                if(isConnected[src][i] == 1) DFS(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false);
        int cnt=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                DFS(i,isConnected,visited);
                cnt++;
            }
        }
        return cnt;
    }
};