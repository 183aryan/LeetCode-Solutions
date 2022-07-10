class Solution {
public:
    int f(vector<int>& cost,int i, vector<int>& dp){
        if(i < 0) return 0;
        if(i == 0 || i == 1) return cost[i];
        
        if(dp[i] != -1) return dp[i];
        
        int one = cost[i] + f(cost,i-1,dp);
        int two = cost[i] + f(cost,i-2,dp);
        
        return dp[i] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        
        return min(f(cost,n-1,dp),f(cost,n-2,dp));
    }
};