class Solution {
public:
    int f(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& vec){
        if(j<0 || j >=vec[0].size()) return 1e5+7;
        if(i == 0) return vec[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int st = vec[i][j] + f(i-1, j, dp, vec);
        int lt = vec[i][j] + f(i-1, j-1, dp, vec);
        int rt = vec[i][j] + f(i-1, j+1, dp, vec);
        
        return dp[i][j] = min(st, min(lt, rt));
    }
    int minFallingPathSum(vector<vector<int>>& vec) {
        int n=vec.size();
        int m=vec[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int mini = 1e5+7;
        
        for(int j=0;j<m;j++){
            mini = min(mini, f(n-1, j, dp, vec));
        }
        return mini;
    }
};