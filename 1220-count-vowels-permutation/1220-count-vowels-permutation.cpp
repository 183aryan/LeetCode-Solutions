class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<char,vector<char>> m ={ {'s',{'a','e','i','o','u'}},{'a',{'e'}},{'e',{'a','i'}},{'i',{'a','e','o','u'}},{'o',{'i','u'}},{'u',{'a'}}};
    
    unordered_map<char,vector<int>> dp;
    
    int f(int n,char used){
        if(n == 0) return 1;
        
        if(dp[used][n] != 0) return dp[used][n];
        
        for(auto x:m.at(used)){
            dp[used][n] = (dp[used][n] + f(n-1,x))%mod;
        }
        
        return dp[used][n];
    }
    int countVowelPermutation(int n) { 
        dp['s'] = vector<int>(n+1,0);
        dp['a'] = vector<int>(n+1,0);
        dp['e'] = vector<int>(n+1,0);
        dp['i'] = vector<int>(n+1,0);
        dp['o'] = vector<int>(n+1,0);
        dp['u'] = vector<int>(n+1,0);
        
        return f(n,'s');
    }
};