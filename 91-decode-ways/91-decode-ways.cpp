class Solution {
public:
    int f(int ind, string& s, vector<int>& dp){
        if(s[ind] == '0') return 0;
        if(ind >= s.size()) return 1;
        if(dp[ind] != -1) return dp[ind];
        int one = f(ind+1, s, dp);
        int two = 0;
        if(ind+1 < s.size() && ((s[ind] == '1' && s[ind+1] <= '9') || (s[ind]=='2' && s[ind+1] <= '6'))){
            two = f(ind+2, s, dp);
        }
        return dp[ind] = one + two;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.size(), -1);
        return f(0, s, dp);
    }
};