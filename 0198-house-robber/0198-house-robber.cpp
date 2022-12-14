class Solution {
public:
//     int f(int ind, vector<int>& nums, vector<int>& dp){
//         if(ind < 0) return 0;
//         if(ind == 0) return nums[ind];
        
//         if(dp[ind] != -1) return dp[ind];
        
//         int take = nums[ind] + f(ind-2, nums, dp);
//         int not_take = f(ind-1, nums, dp);
        
//         return dp[ind] = max(take, not_take);
//     }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        
        // return f(nums.size()-1, nums, dp);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i >= 2) take += dp[i-2];
            int not_take = 0;
            if(i >= 1) not_take += dp[i-1];
            
            dp[i] = max(take, not_take);
        }
        return dp[nums.size()-1];
    }
};