class Solution {
public:
    bool f(int ind,int tar,vector<int> &arr,vector<vector<int>> &dp){
        if(tar == 0) return true;
        if(ind == 0) return (arr[0] == tar);
        if(dp[ind][tar] != -1) return dp[ind][tar];
        bool notTake = f(ind-1,tar,arr,dp);
        bool take = false;
        if(tar >= arr[ind]) take = f(ind-1,tar-arr[ind],arr,dp);
    
        return dp[ind][tar] = notTake | take;
    }

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(n-1,k,arr,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        if(total%2) return false;
        return subsetSumToK(n,total/2,nums);
    }
};