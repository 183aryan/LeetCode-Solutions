class Solution {
public:
    vector<vector<int>> adj;

    int dfs(vector<bool>& hasApple,int node,int d,int prev){
        int result=0;
        int temp;
        for(int &i:adj[node]){
            if(i!=prev){
                    temp=dfs(hasApple,i,d+1,node);
                    if(temp){
                        result+=temp-d;
                    }
                }
        }
        
        if(result || hasApple[node]){
            return result+d;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(hasApple,0,0,-1)*2;
    }
};