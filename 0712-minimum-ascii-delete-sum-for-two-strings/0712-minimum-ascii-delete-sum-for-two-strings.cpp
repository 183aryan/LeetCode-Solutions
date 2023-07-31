class Solution {
public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == s1.size() and j == s2.size()) return 0;
        if(i == s1.size() || j == s2.size()){
            int x=0;
            for(int p=i;p<s1.size();p++) x+=int(s1[p]);
            for(int p=j;p<s2.size();p++) x+=int(s2[p]);
            return x;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) ans = f(i+1, j+1, s1, s2, dp);
        else ans = min((int)s1[i]+f(i+1, j, s1, s2, dp), (int)s2[j]+f(i, j+1, s1, s2, dp));
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return f(0, 0, s1, s2, dp);
    }
};