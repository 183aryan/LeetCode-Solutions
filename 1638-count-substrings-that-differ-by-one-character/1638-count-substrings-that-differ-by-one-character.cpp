class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                int diff=0;
                for(int k=0;k<min(s.size()-i, t.size()-j);k++){
                    if(s[k+i] != t[k+j]) diff++;
                    if(diff > 1) break;
                    ans += diff;
                }
            }
        }
        return ans;
    }
};