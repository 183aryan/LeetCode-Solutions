#include<bits/stdc++.h>
class Solution {
public:
//     int f(int ind, vector<int> &nums, vector<int> &dp){
//         if(ind >= nums.size()-1) return 0;
        
//         if(dp[ind]  != -1) return dp[ind];
        
//         long long int mini = INT_MAX;
        
//         for(int i=1;i<=nums[ind];i++){
//             mini = min(mini, (long long)1+f(ind+i, nums, dp));
//         }
//         return dp[ind] = mini;
//     }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> dp(n+1, INT_MAX);
        // return f(0, nums, dp);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            long long int mini = INT_MAX;
            bool flag=false;
            for(int j=1;j<=nums[i];j++){
                if(i+j >= n-1){
                    dp[i] = 1;
                    flag = true;
                    break;
                }
                mini = min(mini, 1+dp[i+j]);
                dp[i] = mini;
            }
        }
        return dp[0];
    }
};