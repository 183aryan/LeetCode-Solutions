class Solution {
public:
//     int f(int i, int j, vector<int>& nums1, vector<int> nums2, vector<vector<int>>& dp){
//         if(i < 0 || j < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(nums1[i] == nums2[j]){
//             dp[i][j] = 1 + f(i - 1, j - 1, nums1, nums2, dp);
//         }
//         else dp[i][j] = max(f(i, j - 1, nums1, nums2, dp), f(i - 1, j, nums1, nums2, dp));
        
//         return dp[i][j];
//     }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        // return f(n-1, m-1, nums1, nums2, dp);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};