class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        // unordered_map<char, int> um1, um2;
        
        vector<int> s1(26,0), s2(26, 0), s3(26, 0), s4(26, 0);
        
        for(int i=0;i<word1.size();i++){
            s1[word1[i] - 'a']++;
            s2[word1[i] - 'a'] = 1;
        }
        
        for(int i=0;i<word2.size();i++){
            s3[word2[i] - 'a']++;
            s4[word2[i] - 'a'] = 1;
        }
        
        sort(s1.begin(), s1.end());
        sort(s3.begin(), s3.end());
        
        return s1 == s3 and s2 == s4;
        
    }
};