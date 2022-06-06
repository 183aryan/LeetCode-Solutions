class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int pick=INT_MIN,not_pick=INT_MIN;
        /*if(ind > 1)*/ pick = nums[ind] + f(ind-2,nums,dp);
        /*if(ind > 0)*/ not_pick = 0 + f(ind-1,nums,dp);
        
        return dp[ind] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size(),-1);
        return f(n-1,nums,dp);
    }
};