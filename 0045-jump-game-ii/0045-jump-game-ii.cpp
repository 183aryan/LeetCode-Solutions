#include<bits/stdc++.h>
class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind >= nums.size()-1) return 0;
        
        if(dp[ind]  != -1) return dp[ind];
        
        long long int mini = INT_MAX;
        
        for(int i=1;i<=nums[ind];i++){
            mini = min(mini, (long long)1+f(ind+i, nums, dp));
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return f(0, nums, dp);
    }
};