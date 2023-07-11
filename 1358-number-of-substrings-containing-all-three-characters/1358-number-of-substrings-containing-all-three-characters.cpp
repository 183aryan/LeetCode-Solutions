class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> um;
        int i=0, j=0, n = s.size();
        int cnt=0;
        while(j < s.size()){
            um[s[j]]++;
            while(um['a'] and um['b'] and um['c']){
                cnt += (n - j);
                um[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};