class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        vector<int> f1(26, 0) , f2(26, 0);
        
        for(int i=0;i<p.size();i++) f1[p[i]-'a']++;
        
        for(int i=0;i<s.size();i++){
            f2[s[i]-'a']++;
            if(i >= p.size()) f2[s[i - p.size()] - 'a']--;
            if(f1 == f2) v.push_back(i+1-p.size());
        }
        return v;
    }
};