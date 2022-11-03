class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> um;
        for(int i=0;i<words.size();i++){
            um[words[i]]++;
        }
        int ans=0;
        bool flag = false;
        for(auto it:um){
            string s = it.first;
            string t = s;
            reverse(t.begin(), t.end());
            if(s == t){
                 ans += it.second/2; 
                 if(it.second%2) flag = true;
            }
            else{
                if(um.find(t) != um.end()){
                    ans += min(it.second, um[t]);
                    um.erase(t);
                }
            }
         }
         ans *= 4;
         if(flag) ans += 2;
         return ans;
    }
};