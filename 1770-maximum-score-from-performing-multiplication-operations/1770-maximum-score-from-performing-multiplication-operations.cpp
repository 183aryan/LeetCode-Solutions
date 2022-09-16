class Solution {
public:
    int f(int i, int l, vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& dp){
        int n = nums.size();
        if(i == multipliers.size()) return 0;
        if(dp[l][i] != INT_MIN) return dp[l][i];
        
        int r = (n-1)-(i-l);
        
        int first = nums[l]*multipliers[i] + f(i+1,l+1,nums,multipliers,dp);
        int last = nums[r]*multipliers[i] + f(i+1,l,nums,multipliers,dp);
        
        return dp[l][i] = max(first, last);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
         int m=multipliers.size();
        int n=nums.size();
        vector<vector<int>> dp(m,vector<int> (m,INT_MIN));
        return f(0,0,nums,multipliers,dp);
    }
};