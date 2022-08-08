class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxi = 1;
        
        for(int i=0;i<nums.size();i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i]) dp[i] = max(dp[i],1+dp[prev]);
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};