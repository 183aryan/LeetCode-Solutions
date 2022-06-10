class Solution {
public:
    vector<vector<int>> adj[1009];
    int cost[1009],time[1009];
    
    int dijkstra(int src,int des,int maxTime){
        for(int i=1;i<=des;i++){
            cost[i] = INT_MAX;
            time[i] = INT_MAX;
        }
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        pq.push({cost[src],time[src],src});
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int c = x[0];
            int t = x[1];
            int v = x[2];
            
            for(int i=0;i<adj[v].size();i++){
                
                if(t + adj[v][i][1] <= maxTime){
                    if(c + adj[v][i][2] < cost[adj[v][i][0]]){
                        cost[adj[v][i][0]] = c + adj[v][i][2];
                    
                        time[adj[v][i][0]] = t + adj[v][i][1];
                        pq.push({cost[adj[v][i][0]],time[adj[v][i][0]],adj[v][i][0]});
                    } 
                    else if(time[adj[v][i][0]] > t + adj[v][i][1]){
                        time[adj[v][i][0]] = t + adj[v][i][1];
                        pq.push({c + adj[v][i][2],time[adj[v][i][0]],adj[v][i][0]});
                    }
                }
            }
        }
        return cost[des];
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int x,y,t,n = passingFees.size();
        
        for(int i=0;i<edges.size();i++){
            x = edges[i][0];
            y = edges[i][1];
            t = edges[i][2];
            
            adj[x].push_back({y,t,passingFees[y]});                                                     adj[y].push_back({x,t,passingFees[x]});
        }
        
        cost[0] = passingFees[0];
        time[0] = 0;
        
        int ans = dijkstra(0,n-1,maxTime);
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};