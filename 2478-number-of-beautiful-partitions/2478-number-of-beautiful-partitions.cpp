class Solution {
public:
    int dp[1007][1007];
    const int mod=1e9+7;
    
    bool isPrime(char ch){
        int temp = ch - '0';
        return (temp == 2 || temp == 3 || temp == 5 || temp == 7);
    }
    
    int f(int index, int k, int minLen, string& s){
        if(index == s.size() and k == 0) return 1;
        if(index >= s.size() || k < 0) return 0;
        
        if(dp[index][k]!=-1) return dp[index][k];
        
        int notPick = f(index+1, k, minLen, s)%mod;
        int pick = 0;
        if(isPrime(s[index]) and !isPrime(s[index-1])) pick = f(index+minLen,  k-1, minLen, s)%mod;
        
        return dp[index][k] = (pick + notPick)%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp, -1, sizeof(dp));
        int n=s.size();
        if(!isPrime(s[0]) || isPrime(s[n-1])) return 0;
        
        return f(minLength, k-1, minLength, s);
    }
};