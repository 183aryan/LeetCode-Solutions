class Solution {
public:
    vector<pair<int, int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    double f(int i, int j, int n, int k, vector<vector<vector<double>>>& dp){
        if(i  < 0 || j < 0 || i >= n || j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        double ans = 0;
        for(int ii=0;ii<8;ii++){
            int new_i = i+dir[ii].first;
            int new_j = j+dir[ii].second;
            
            ans += f(new_i, new_j, n, k-1, dp);
        }
        return dp[i][j][k] = (ans/8);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double> (k+1, -1)));
        return f(row, column, n, k, dp);
    }
};