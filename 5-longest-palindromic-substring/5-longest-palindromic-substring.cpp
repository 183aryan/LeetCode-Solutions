class Solution {
public:
    string lps(string s1,string s2,int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxi = 0;
        string res = "";
        
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=n;j++) dp[0][j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    if(dp[i][j] > maxi){
                        string temp = s1.substr(i-dp[i][j],dp[i][j]);
                        string revtemp = temp;
                        reverse(revtemp.begin(),revtemp.end());
                        if(revtemp == temp){
                            maxi = dp[i][j];
                            res = temp;
                        }
                    }
                }
                else dp[i][j] = 0;
            }
        }
        return res;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return lps(s,s2,n);
    }
};