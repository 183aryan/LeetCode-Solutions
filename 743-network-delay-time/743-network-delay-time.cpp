class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        for(int i=1;i<n;i++){
            for(auto t:times){
                dist[t[1]] = min(dist[t[1]],dist[t[0]] + t[2]);
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9)
                return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};