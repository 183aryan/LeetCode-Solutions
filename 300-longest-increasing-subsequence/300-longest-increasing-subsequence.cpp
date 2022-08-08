class Solution {
public:
    int f(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        int len = 0 + f(ind+1,prev,nums,dp);
        
        if(prev == -1 || nums[ind] > nums[prev]) len = max(len, 1+f(ind+1,ind,nums,dp));
        
        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};