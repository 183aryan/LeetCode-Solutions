class Solution {
public:
    bool static compare(string &s1,string &s2)
    {
         return s1.size() > s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        
        int n=words.size();
        unordered_map<string,int> m;
        for(int i=0;i<n;i++) m[words[i]] = i;
        
        vector<int> dp(n+1,1);
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                string s = words[i].substr(0,j) + words[i].substr(j+1);
                if(m.find(s) != m.end()){
                    dp[m[s]] = max(dp[m[s]],1+dp[i]);
                    ans = max(ans,dp[m[s]]);
                }
            }
        }
        return ans;
    }
};