class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> v;
        unordered_map<string, int> um;
        
        for(auto it:words){
            um[it]++;
        }
        
        for(auto it:words){
            int n=it.size();
            vector<int> dp(n+1, 0);
            dp[0]=1;
            for(int i=0;i<n;i++){
                if(dp[i] == 0) continue;
                for(int j=i+1;j<=n;j++){
                    if(j-i<n and um[it.substr(i, j-i)] > 0) dp[j] = 1;
                }
                if(dp[n]){
                    v.push_back(it);
                    break;
                }
            }
        }
        return v;
    }
};