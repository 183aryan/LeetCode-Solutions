class Solution {
public:
    int f(int index, int target, vector<int>& nums, vector<int>& dp){
        if(index >= nums.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        int maxi = INT_MIN;
        
        for(int i=index+1;i<nums.size();i++){
            if(abs(nums[i] - nums[index]) <= target){
                maxi = max(maxi, 1 + f(i, target, nums, dp));
            }
        }
        return dp[index] = maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = f(0, target, nums, dp);
        return (ans <= 0 ? -1 : ans);
    }
};