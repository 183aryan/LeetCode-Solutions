class Solution {
public:
    int mod = 1e9+7;
    int f(int i, int j, vector<string>& words, string& target, vector<vector<int>>& freq, vector<vector<int>>& dp){
        if(j == target.size()) return 1;
        if(i == words[0].size()) return 0;
        

         if(dp[i][j] != -1) return dp[i][j];
        
        int notPick = f(i+1, j, words, target, freq, dp)%mod;
        int pick = 0;
        
        int targetCh = target[j] - 'a';

        if (freq[targetCh][i] != 0)
        {
            int currWays = freq[targetCh][i];
            int nextWays = f(i + 1, j + 1,words, target, freq, dp);
            pick = (1LL*currWays%mod * 1LL*nextWays%mod) % mod;
        }
        
        return dp[i][j] = (pick%mod + notPick%mod)%mod;
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(words[0].size(), vector<int> (target.size(), -1));
        vector<vector<int>> freq(26, vector<int>(words[0].size(), 0));
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].size();j++){
                freq[words[i][j] - 'a'][j]++;
            }
        }
        return f(0, 0, words, target, freq, dp);
    }
};