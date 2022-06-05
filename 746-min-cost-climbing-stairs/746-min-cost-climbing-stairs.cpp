class Solution {
public:
    // int minCost(vector<int>& cost,int i,vector<int>& dp){
    //     if(i < 0 ) return 0;
    //     if(i == 0 || i == 1) return cost[i];
    //     if(dp[i] != -1) return dp[i];
    //     int one = cost[i] + minCost(cost,i-1,dp);
    //     int two = cost[i] + minCost(cost,i-2,dp);
    //     // return dp[i] = cost[i] + min(minCost(cost,i-1,dp),minCost(cost,i-2,dp));
    //     return dp[i] = min(one,two);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        // return min(minCost(cost,n-1,dp),minCost(cost,n-2,dp));
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr = 0;
        for(int i=2;i<n;i++){
            curr = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1,prev2);
    }
};