class Solution {
public:
    int mod = 1e9+7;
    
    int f(int index, string& s, int k, vector<int>& dp){
        if(index == s.size()) return 1;
        
        if(dp[index] != -1) return dp[index];
        
        long long int num = 0;
        long long int ans= 0;
        
        for(int i=index;i<s.size();i++){
            num = (num*10) + (s[i]-'0');
            
            if(num <= k and num >= 1) ans = (ans + f(i+1, s, k, dp))%mod;
            else break;
        }
       return dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return f(0, s, k, dp);
    }
};