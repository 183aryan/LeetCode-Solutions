class Solution {
public:
    bool check(string& s1, string&s2){
        if(s1.size() != s2.size()+1) return false;
        
        int first=0,second=0;
        while(first<s1.size()){
            if(s1[first] == s2[second] and second < s2.size()){
                first++;
                second++;
            }
            else first++;
        }
        
        if(first == s1.size() and second == s2.size()) return true;
        return false;
    }
    static bool cmp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),cmp);
        int n=words.size();
        
        vector<int> dp(n, 1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i], words[prev]) and 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};