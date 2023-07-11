class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        int maxi = 0;
        int cnt=-1;
        unordered_map<char, int> um;
        while(j < s.size()){
            um[s[j]]++;
            maxi = max(maxi, um[s[j]]);
            while((j-i+1) - maxi > k){
                um[s[i++]]--;
            }
            cnt = max(cnt, j-i+1);
            j++;
        }
        return cnt;
    }
};