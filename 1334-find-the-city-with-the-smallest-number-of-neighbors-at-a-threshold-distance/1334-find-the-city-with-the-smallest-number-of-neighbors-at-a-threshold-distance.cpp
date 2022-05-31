class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 20000)); //int_max par overflow aa rha h
        
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(auto &edge : edges) {
            dist[edge[0]][edge[1]] = edge[2]; 
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int mn = INT_MAX;
        int city;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto x:dist[i]){
                if(x <= distanceThreshold) cnt++;
            }
            if(cnt <= mn){
                mn = cnt;
                city = i;
            }
        }
        return city;
    }
};