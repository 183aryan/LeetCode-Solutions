class Solution {
public:
    bool f(int idx, string s, vector<string>& wordDict, unordered_set<string>& st, vector<int>& dp){
        if(idx == s.size()) return 1;
            
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(st.count(s.substr(idx, i-idx+1))){
                if(f(i+1, s, wordDict, st, dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(0, s, wordDict, st, dp);
    }
};