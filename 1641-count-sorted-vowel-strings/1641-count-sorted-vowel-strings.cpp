class Solution {
public:
    //memoization
//     int f(int ind, int n, vector<vector<int>>& dp, string& s){
//         if(ind >= 5) return 0;
//         if(n == 0) return 1;
        
//         if(dp[ind][n] != -1) return dp[ind][n];
        
//         int take = f(ind, n-1, dp, s);
//         int not_take = f(ind+1, n, dp, s);
        
//         return dp[ind][n] = take + not_take;
//     }
    int countVowelStrings(int n) {
        // string s = "aeiou";
        // vector<vector<int>> dp(5, vector<int> (n+1, -1));
        // return f(0, n, dp, s);
        
        int a=1, e=1, i=1, o=1, u=1;
        
        for(int j=2;j<=n;j++){
            a = a+e+i+o+u;
            e = e+i+o+u;
            i = i+o+u;
            o = o+u;
            u = u;
        }
        
        return a+e+i+o+u;
    }
};