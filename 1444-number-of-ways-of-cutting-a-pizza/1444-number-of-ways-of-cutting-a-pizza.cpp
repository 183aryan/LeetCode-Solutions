class Solution {
public:
    int f(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum){
        if(preSum[r][c] == 0) return 0;
        if(k == 0) return 1;
        if(dp[k][r][c] != -1) return dp[k][r][c];
        
        int ans=0;
        
        for(int nr=r+1;nr<m;nr++){
            if(preSum[r][c] - preSum[nr][c] > 0){
                ans = (ans + f(m, n, k-1, nr, c, dp, preSum))%1000000007;
            }
        }
        for(int nc=c+1;nc<n;nc++){
            if(preSum[r][c] - preSum[r][nc] > 0){
                ans = (ans + f(m, n, k-1, r, nc, dp, preSum))%1000000007;
            }
        }
        
        return dp[k][r][c] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size();
        int n=pizza[0].size();
        vector<vector<int>> preSum(m+1, vector<int> (n+1, 0));
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                preSum[i][j] = preSum[i][j+1] + preSum[i+1][j] - preSum[i+1][j+1] + (pizza[i][j] == 'A');
                
            }
        }
        return f(m, n, k-1, 0, 0, dp, preSum);
    }
};