#include<bits/stdc++.h>
class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()-1) return 0;
        if(dp[ind] != 1e9) return dp[ind];
        int x = 10001;
        for(int j=1;j<=nums[ind];j++){
            dp[ind] = min(dp[ind], 1 + f(ind+j, nums, dp));
        }
        return dp[ind];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e9);
        return f(0, nums, dp);
    }
};