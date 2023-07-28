class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp, bool flag){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if(flag){
            res = max(nums[i] + f(i+1, j, nums, dp, false), nums[j] + f(i, j-1, nums, dp, false));
        }
        else res = min(-nums[i] + f(i+1, j, nums, dp, true), -nums[j] + f(i, j-1, nums, dp, true));
        
        return dp[i][j] = res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        bool flag=true;
        vector<vector<int>> dp(21, vector<int>(21, -1));
        int ans = f(0, nums.size()-1, nums, dp, flag);
        return (ans >= 0) ? true : false;
    }
};