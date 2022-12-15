class Solution {
public:
//     int f(int ind1, int ind2, string& text1, string& text2, vector<vector<int>>& dp){
//         if(ind1 < 0 || ind2 < 0) return 0;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
//         if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, text1, text2, dp);
//         return dp[ind1][ind2] = 0 + max(f(ind1,ind2-1,text1,text2,dp),f(ind1-1,ind2,text1,text2,dp));
//     }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,0));
        // return f(text1.size()-1, text2.size()-1, text1, text2, dp);
        
        for(int i=0;i<text1.size();i++) dp[i][0] = 0;
        for(int j=0;j<text2.size();j++) dp[0][j] = 0;
        
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};