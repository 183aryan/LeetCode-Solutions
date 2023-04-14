class Solution {
public:
//     int f(int ind1,int ind2,string& s,string& t,vector<vector<int>>& dp){
//         if(ind1 < 0 || ind2 < 0) return 0;
        
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(s[ind1] == t[ind2]) return dp[ind1][ind2] = 1 + f(ind1 - 1,ind2 - 1,s,t,dp);
    
//         return dp[ind1][ind2] = 0 + max(f(ind1-1,ind2,s,t,dp), f(ind1,ind2-1,s,t,dp));
//     }
    int longestPalindromeSubseq(string s) {
        int n =s.length();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int m = s1.size();
        // if(n==1) return 1;
        // string t = s;
        // reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        // return f(s.size()-1,t.size()-1,s,t,dp);
        
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == s1[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};