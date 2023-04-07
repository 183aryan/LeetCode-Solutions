class Solution {
public:
    int dp[1005][52];
    int f(int index, int m, vector<int>& nums){
        if(index == nums.size() and m == 0) return 1;
        
        if(index == nums.size()) return INT_MAX;
        
        if(m == 0) return INT_MAX;
        
        if(dp[index][m] != -1) return dp[index][m];
        
        int ans = INT_MAX, curr=0;
        for(int i=index;i<nums.size();i++){
            curr += nums[i];
            
            ans = min(ans, max(curr, f(i+1, m-1, nums)));
        }
        
        return dp[index][m] = ans;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof(dp));
        
        if(nums.size() == 1 and nums[0] == 0) return 0;
        
        return f(0, m, nums);
    }
};