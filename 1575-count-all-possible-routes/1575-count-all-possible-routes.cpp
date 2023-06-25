class Solution {
public:
    int mod = 1e9+7;
    int f(int city, int finish, int fuel, vector<int>& locations, vector<vector<int>>& dp){
        if(fuel < 0) return 0;
        
        if(dp[city][fuel] != -1) return dp[city][fuel];
        
        int ans = (city == finish);
        for(int i=0;i<locations.size();i++){
            if(i != city){
                ans = (ans + f(i, finish, fuel - abs(locations[city] - locations[i]), locations, dp))%mod;
            }
        }
        return dp[city][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel+1, -1));
        return f(start, finish, fuel, locations, dp)%mod;
    }
};