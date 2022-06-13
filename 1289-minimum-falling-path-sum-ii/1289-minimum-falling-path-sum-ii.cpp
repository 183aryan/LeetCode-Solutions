class Solution {
public:
    int f(int i,int j,vector<vector<int>>& vec,vector<vector<int>>& dp){
        if(j < 0 || j >= vec[0].size()) return 1e9;
        if(i == 0) return vec[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int move = 1e9;;
        for(int k=0;k<vec[j].size();k++){
            if(k == j) continue;
            else{
                move = min(move,vec[i][j] + f(i-1,k,vec,dp));
            }
        }
    
        return dp[i][j] = move;
    }
    
    int minFallingPathSum(vector<vector<int>>& vec) {
        int n = vec.size();
        int m = vec[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
    
        int mx = 1e9;
        for(int j=0;j<m;j++){
            mx = min(mx,f(n-1,j,vec,dp));
        }
        return mx;
    }
};